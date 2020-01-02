# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
import sklearn
import pandas as pd
import os
import sys
import time
import tensorflow as tf
from tensorflow import keras

print(tf.__version__)
print(sys.version_info)

for module in mpl,np,pd,tf,keras:
    print(module.__name__, module.__version__)
    

fashion_mnist=keras.datasets.fashion_mnist
(x_train_all,y_train_all),(x_test,y_test)=fashion_mnist.load_data()
#训练集拆分为训练集和验证集
x_valid,x_train=x_train_all[:5000],x_train_all[5000:]
y_valid,y_train=y_train_all[:5000],y_train_all[5000:]

print(x_valid.shape,y_valid.shape)
print(x_train.shape,y_train.shape)

#对数据归一化
from sklearn.preprocessing import StandardScaler
scaler=StandardScaler()
#用这个函数进行归一化需要将数据格式转换为二维x_train:[None,28,28]->[None,784]
#fit_transform记录训练集的均值和方差用于验证集和测试集
x_train_scaled=scaler.fit_transform(x_train.astype(np.float32).reshape(-1,1)).reshape(-1,28,28)
x_valid_scaled=scaler.transform(x_valid.astype(np.float32).reshape(-1,1)).reshape(-1,28,28)
x_test_scaled=scaler.transform(x_test.astype(np.float32).reshape(-1,1)).reshape(-1,28,28)

def show_single_image(img_arr):
    plt.imshow(img_arr,cmap="binary")
    plt.show()
    
show_single_image(x_train[0])

def show_imgs(n_rows,n_cols,x_data,y_data,class_names):
    assert len(x_data)==len(y_data)
    assert n_rows*n_cols<len(x_data)
    for row in range(n_rows):
        for col in range(n_cols):
            index=n_cols*row+col
            plt.subplot(n_rows,n_cols,index+1)
            plt.imshow(x_data[index],cmap="binary",interpolation="nearest")
            plt.axis("off")
            plt.title(class_names[y_data[index]])
    plt.show()

class_names=["T-shirt","Trouser","Pullover","Dress","Coat","sandal","shirt","Sneaker","Bag","Ankle boot"]

show_imgs(3,5,x_train,y_train,class_names)

model=keras.models.Sequential()
model.add(keras.layers.Flatten(input_shape=[28,28]))
model.add(keras.layers.Dense(300,activation="relu"))
model.add(keras.layers.Dense(100,activation="relu"))
model.add(keras.layers.Dense(10,activation="softmax"))
"""
model=keras.models.Sequential(
        [
            keras.layers.Flatten(input_shape=[28,28]),
            keras.layers.Dense(300,activation="relu"),
            keras.layers.Dense(100,activation="relu"),
            keras.layers.Dense(10,activation="softmax")
                ])
"""
#relu: y=max(0,x)
#softmax:将向量变成概率分布。x=[x1,x2,x3],
# y=[e^x1/sum,e^x2/sum,e^x3/sum],sum=e^x1+e^x2+e^x3
#compile方法添加损失函数，优化方法，关心的值，sparse_categorical_crossentropy将y的索引转化为one-hot形式，如果已经是one-hot形式使用categorical_crossentropy就可以
model.compile(loss="sparse_categorical_crossentropy",optimizer="sgd",metrics=["accuracy"])

#查看已经添加的层
model.summary()

#定义需要的callback   Tensorboard需要定义一个文件夹   ModelCheckpoint需要定义一个文件名
#打开Tensorboard命令tensorboard --logdir=callbacks(文件夹的名字)  localhost:6006
logdir='./callbacks'
output_model_file=os.path.join(logdir,"fashion_mnist_model.h5")
if not os.path.exists(logdir):
    os.mkdir(logdir)
callbacks=[
        keras.callbacks.TensorBoard(logdir),
        keras.callbacks.ModelCheckpoint(output_model_file,save_best_only=True),
        keras.callbacks.EarlyStopping(patience=5,min_delta=1e-3)]

history=model.fit(x_train,y_train,epochs=10,validation_data=(x_valid,y_valid),
                  callbacks=callbacks)

type(history)

history.history

def plot_learning_curves(history):
    pd.DataFrame(history.history).plot(figsize=(8,5))
    plt.grid(True)
    plt.gca.set_ylim(0,1)
    plt.show()

model.evaluate(x_test,y_test)