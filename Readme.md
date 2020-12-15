# AMT Wsman and MEI library from LMS

Note: this is an experimental/demonstration project containing partial copy of Intel LMS (https://github.com/intel/lms) component which sufficient to develop AMT client on Windows and Linux.

Use at your own risk.



# Linux build requirement -- Ubuntu 20.04

A good practice is to install "build-essential" group package followed by dependecies.
```
$ sudo apt install build-essential cmake g++ python3 libglib2.0-dev libcurl4-openssl-dev libxerces-c-dev libnl-3-dev libnl-route-3-dev libxml2-dev xsltproc docbook-xsl
```

# How to compile on Linux

```
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_CXX_COMPILER=g++ ..
$ make -j$(nproc)
```
Once the build is complete, you should see few folders inside build folder.


# Testing sample code

Go to folder build/WsmanClient/WsmanClientExample, there should be a binary code named "WsmanClientExample".
Here is an example of its output.
```
$ sudo ./WsmanClientExample 127.0.0.1 admin yourS3cretP@ssword
Network interface enabled  : 1
Digest Realm               : Digest:AF6E0000000000000000000000000000
IdleWakeTimeout            : 65535
AMT Hostname               : NUCMC
Domain Name                : 
Ping Response enabled      : 1
Wsman Only Mode            : 0
Preferred Address family   : 0
```
