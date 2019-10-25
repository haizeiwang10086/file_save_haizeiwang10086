/*
Navicat MySQL Data Transfer

Source Server         : dh
Source Server Version : 50560
Source Host           : localhost:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50560
File Encoding         : 65001

Date: 2019-10-19 11:00:29
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `info`
-- ----------------------------
DROP TABLE IF EXISTS `info`;
CREATE TABLE `info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `content` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `remarks` varchar(500) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of info
-- ----------------------------
INSERT INTO `info` VALUES ('28', '邮箱名', 'wangzq@daheng-image.com', '');
INSERT INTO `info` VALUES ('29', 'RDM', 'http://192.168.70.60:2000', '');
INSERT INTO `info` VALUES ('30', 'ftp资料', 'ftp://192.168.70.20:6000/pub/', '');
INSERT INTO `info` VALUES ('31', '财务', 'http://47.92.80.136/k3Cloud', '');
INSERT INTO `info` VALUES ('32', '速盘激活码', '78325D04-DB3C-DF02-230D-E5B14F2FA8D1', '');
INSERT INTO `info` VALUES ('33', 'ERP考勤', 'http://115.28.149.68:8080/', '');
INSERT INTO `info` VALUES ('34', 'RDM 登录地址内网', 'http://192.168.70.60:2000', '');
INSERT INTO `info` VALUES ('35', 'RDM 登录地址外网', 'http://106.120.95.66:2000/', '');
INSERT INTO `info` VALUES ('36', 'QT下载下载网址', 'https://download.qt.io/archive/qt/', '');
INSERT INTO `info` VALUES ('37', '无线网', '账号 Daheng 密码：Daheng@123', '');
INSERT INTO `info` VALUES ('38', '金蝶', 'http://47.92.80.136/K3Cloud/html5/index.aspx', '');
INSERT INTO `info` VALUES ('39', '工资条查询', 'http://47.92.80.136/K3Cloud/html5/index.aspx', '');
INSERT INTO `info` VALUES ('40', '建行卡号', '6217000010145761857', 'qdc');
