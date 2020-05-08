# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '../ui/rpi.ui'
#
# Created by: PyQt5 UI code generator 5.14.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets
from threading import *
import socket			 

def find_ip():
    import scapy.all as scapy 
    request = scapy.ARP() 
    request.pdst = "192.168.0.1/24"
    broadcast = scapy.Ether() 
    broadcast.dst = "ff:ff:ff:ff:ff:ff"
    request_broadcast = broadcast / request 
    clients = scapy.srp(request_broadcast, timeout = 1)[0] 
    for element in clients:
        ip = element[1].psrc
        mac = element[1].hwsrc
    print(ip)
    return ip

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        self.s = socket.socket()
        self.port=3000
        self.ip="127.0.0.1"
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(535, 278)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.progressBar = QtWidgets.QProgressBar(self.centralwidget)
        self.progressBar.setGeometry(QtCore.QRect(0, 210, 531, 23))
        self.progressBar.setProperty("value", 0)
        self.progressBar.setObjectName("progressBar")
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(0, 10, 532, 194))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout_4.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.lbl_ip = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(10)
        self.lbl_ip.setFont(font)
        self.lbl_ip.setObjectName("lbl_ip")
        self.horizontalLayout_3.addWidget(self.lbl_ip)
        self.lineEditIP = QtWidgets.QLineEdit(self.layoutWidget)
        self.lineEditIP.setObjectName("lineEditIP")
        self.horizontalLayout_3.addWidget(self.lineEditIP)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.lbl_port = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(10)
        self.lbl_port.setFont(font)
        self.lbl_port.setObjectName("lbl_port")
        self.horizontalLayout_2.addWidget(self.lbl_port)
        self.lineEditPort = QtWidgets.QLineEdit(self.layoutWidget)
        self.lineEditPort.setText("")
        self.lineEditPort.setObjectName("lineEditPort")
        self.horizontalLayout_2.addWidget(self.lineEditPort)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.verticalLayout_2.addLayout(self.verticalLayout)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.pbAutoConnect = QtWidgets.QPushButton(self.layoutWidget)
        self.pbAutoConnect.setObjectName("pbAutoConnect")
        self.horizontalLayout.addWidget(self.pbAutoConnect)
        self.pbConnect = QtWidgets.QPushButton(self.layoutWidget)
        self.pbConnect.setObjectName("pbConnect")
        self.horizontalLayout.addWidget(self.pbConnect)
        self.pbAllTest = QtWidgets.QPushButton(self.layoutWidget)
        self.pbAllTest.setObjectName("pbAllTest")
        self.horizontalLayout.addWidget(self.pbAllTest)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.verticalLayout_3.addLayout(self.verticalLayout_2)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.pbBle = QtWidgets.QPushButton(self.layoutWidget)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("../ui/Bluetooth_FM_Color.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pbBle.setIcon(icon)
        self.pbBle.setObjectName("pbBle")
        self.gridLayout.addWidget(self.pbBle, 0, 0, 1, 1)
        self.pbWifi = QtWidgets.QPushButton(self.layoutWidget)
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap("../ui/Wireless-icon.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pbWifi.setIcon(icon1)
        self.pbWifi.setObjectName("pbWifi")
        self.gridLayout.addWidget(self.pbWifi, 0, 1, 1, 1)
        self.pbGpio = QtWidgets.QPushButton(self.layoutWidget)
        self.pbGpio.setObjectName("pbGpio")
        self.gridLayout.addWidget(self.pbGpio, 0, 2, 1, 1)
        self.pbAudio = QtWidgets.QPushButton(self.layoutWidget)
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap("../ui/audio.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pbAudio.setIcon(icon2)
        self.pbAudio.setObjectName("pbAudio")
        self.gridLayout.addWidget(self.pbAudio, 1, 0, 1, 1)
        self.pbCamera = QtWidgets.QPushButton(self.layoutWidget)
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap("../ui/camera.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pbCamera.setIcon(icon3)
        self.pbCamera.setObjectName("pbCamera")
        self.gridLayout.addWidget(self.pbCamera, 1, 1, 1, 1)
        self.pbVideo = QtWidgets.QPushButton(self.layoutWidget)
        icon4 = QtGui.QIcon()
        icon4.addPixmap(QtGui.QPixmap("../ui/video.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pbVideo.setIcon(icon4)
        self.pbVideo.setObjectName("pbVideo")
        self.gridLayout.addWidget(self.pbVideo, 1, 2, 1, 1)
        self.verticalLayout_3.addLayout(self.gridLayout)
        self.horizontalLayout_4.addLayout(self.verticalLayout_3)
        self.tblog = QtWidgets.QTextBrowser(self.layoutWidget)
        self.tblog.setObjectName("tblog")
        self.horizontalLayout_4.addWidget(self.tblog)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 535, 20))
        self.menubar.setObjectName("menubar")
        self.menuHelp = QtWidgets.QMenu(self.menubar)
        self.menuHelp.setObjectName("menuHelp")

        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionAbout = QtWidgets.QAction(MainWindow)
        self.actionAbout.setObjectName("actionAbout")
        self.menuHelp.addAction(self.actionAbout)
        self.menubar.addAction(self.menuHelp.menuAction())
        
        self.pbAutoConnect.clicked.connect(self.auto_connect_server)
        self.pbConnect.clicked.connect(self.connect_server)
        self.pbBle.clicked.connect(self.ble_test)
        self.pbWifi.clicked.connect(self.wifi_test)
        self.pbGpio.clicked.connect(self.gpio_test)
        self.pbAudio.clicked.connect(self.audio_test)
        self.pbCamera.clicked.connect(self.camera_test)
        self.pbVideo.clicked.connect(self.videostream_test)
        self.pbAllTest.clicked.connect(self.all_test)
        self.lineEditIP.setText(self.ip)
        self.lineEditPort.setText(str(self.port))

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.lbl_ip.setText(_translate("MainWindow", "IP Address"))
        self.lbl_port.setText(_translate("MainWindow", "Port NO"))
        self.pbAutoConnect.setText(_translate("MainWindow", "Auto Connect"))
        self.pbConnect.setText(_translate("MainWindow", "Connect"))
        self.pbAllTest.setText(_translate("MainWindow", "All Test"))
        self.pbBle.setText(_translate("MainWindow", "Bluetooth"))
        self.pbWifi.setText(_translate("MainWindow", "Wifi"))
        self.pbGpio.setText(_translate("MainWindow", "GPIO"))
        self.pbAudio.setText(_translate("MainWindow", "Audio"))
        self.pbCamera.setText(_translate("MainWindow", "Camera"))
        self.pbVideo.setText(_translate("MainWindow", "Video"))
        self.menuHelp.setTitle(_translate("MainWindow", "Help"))
        self.actionAbout.setText(_translate("MainWindow", "About"))

    def auto_connect_server(self):
        print("connecting to device")
        self.s.connect((find_ip(), self.port))
        print("Connected")

    def connect_server(self):
        print("connecting to device")
        self.lineEditIP.update()
        self.lineEditPort.update()
        self.ip = self.lineEditIP.text()
        self.port = self.lineEditPort.text()
        self.log("IP : "+self.ip + " Port:"+self.port)
        
        self.s.connect(( self.ip , int(self.port)))
        print("Connected")

    def send_cmd(self,msg):
        print(msg)
        self.log(msg)
        self.s.send(bytes(str(msg),"UTF-8"))

    def ble_test(self):
        self.send_cmd("bluetooth")
        data = self.s.recv(5)
        self.tblog.append("Bluetooth :"+(data.decode()))
        self.progressBar.setValue(10)

    
    def wifi_test(self):
        self.send_cmd("wifi")
        data = self.s.recv(5)
        self.tblog.append("Wifi :"+(data.decode()))
        self.progressBar.setValue(20)

    def gpio_test(self):
        self.send_cmd("gpio")
        data = self.s.recv(5)
        self.tblog.append("gpio :"+(data.decode()))
        self.progressBar.setValue(40)

    def audio_test(self):
        self.send_cmd("audio")
        data = self.s.recv(5)
        self.tblog.append("audio :"+(data.decode()))
        self.progressBar.setValue(60)

    def camera_test(self):
        self.send_cmd("camera")
        data = self.s.recv(5)
        self.tblog.append("camera :"+(data.decode()))
        self.progressBar.setValue(80)

    def videostream_test(self):
        self.send_cmd("videostream")
        data = self.s.recv(50)
        self.tblog.append("videostream :"+(data.decode()))
        import cv2
        cap = cv2.VideoCapture(data.decode())
        while(cap.isOpened()):
            ret, frame = cap.read()
            cv2.imshow('frame', frame)
            if cv2.waitKey(20) & 0xFF == ord('q'):
                self.send_cmd("StopVideoStream")
                break
        cap.release()
        cv2.destroyAllWindows()
        
        self.progressBar.setValue(100)

    def all_test(self):
        self.send_cmd("alltest")
        data = self.s.recv(5)
        self.tblog.append(data)
    
    def log(self,log_str):
        self.statusbar.showMessage(log_str)
#        self.tblog.append(log_str)

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
