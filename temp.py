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
#relu: y=max(0,x)
#softmax:将向量变成概率分布。x=[x1,x2,x3],
# y=[e^x1/sum,e^x2/sum,e^x3/sum],sum=e^x1+e^x2+e^x3
#compile方法添加损失函数，优化方法，关心的值，sparse_categorical_crossentropy将y的索引转化为one-hot形式，如果已经是one-hot形式使用categorical_crossentropy就可以
model.compile(loss="sparse_categorical_crossentropy",optimizer="sgd",metrics=["accuracy"])

#查看已经添加的层
model.layers