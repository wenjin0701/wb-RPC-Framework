# Wrpc - 轻量级 RPC 框架

## 项目简介

Wrpc 是一个轻量级的 RPC (Remote Procedure Call) 框架，基于 C++ 语言开发，提供了简单、高效的远程服务调用能力。本框架采用了 Protobuf 作为序列化工具，使用 ZooKeeper 进行服务注册与发现，基于 Muduo 网络库实现网络通信。

## 项目结构

```
Wrpc/
├── bin/              # 编译输出目录
│   └── test.conf     # 配置文件
├── example/          # 示例代码
│   ├── callee/       # 服务提供者
│   ├── caller/        # 服务调用者
│   ├── user.proto     # Protobuf 服务定义
│   └── user.pb.cc     # Protobuf 生成的代码
├── img/              # 项目图片
├── src/              # 框架源码
│   ├── include/       # 头文件
│   ├── Wrpcapplication.cc  # 应用初始化
│   ├── Wrpcchannel.cc      # 客户端通道
│   ├── Wrpcconfig.cc       # 配置管理
│   ├── Wrpccontroller.cc   # 控制器
│   ├── Wrpcheader.pb.cc    # 协议头
│   ├── Wrpcprovider.cc     # 服务提供者
│   └── zookeeperutil.cc   # ZooKeeper 工具
├── CMakeLists.txt    # 根目录 CMake 文件
├── LICENSE           # 许可证
└── README.md         # 项目说明
```

## 功能特性

- **服务注册与发现**：基于 ZooKeeper 实现服务的注册和发现机制
- **序列化**：使用 Protobuf 进行高效的序列化和反序列化
- **网络通信**：基于 Muduo 网络库实现高性能的网络通信
- **错误处理**：完善的错误处理机制
- **多线程支持**：支持多线程并发调用
- **可配置性**：通过配置文件灵活配置服务参数

## 环境要求

- C++11 及以上
- CMake 3.0 及以上
- Protobuf 3.12.0 及以上
- ZooKeeper 3.4.14 及以上
- Muduo 网络库
- GLog 日志库

## 安装和编译

### 1. 安装依赖

- **Protobuf**：版本 3.12.0 及以上
- **ZooKeeper**：版本 3.4.14 及以上
- **Muduo 网络库**：请参考官方文档安装
- **GLog**：Google 日志库

### 2. 编译项目

1. 克隆项目到本地
2. 创建并进入 build 目录
3. 运行 `cmake ..` 配置项目
4. 运行 `make` 编译项目

## 使用示例

### 1. 定义服务接口

服务接口定义在 `example/user.proto` 文件中，包含登录和注册等 RPC 方法。

### 2. 实现服务提供者

服务提供者的实现位于 `example/callee/Wserver.cc` 文件中，负责处理客户端的 RPC 请求。

### 3. 实现服务调用者

服务调用者的实现位于 `example/caller/Wclient.cc` 文件中，用于向服务提供者发送 RPC 请求。

## 运行方式

### 1. 启动 ZooKeeper 服务

启动本地 ZooKeeper 服务，确保服务正常运行。

### 2. 启动服务提供者

进入 bin 目录，运行服务提供者程序：`./server -i test.conf`

### 3. 运行服务调用者

进入 bin 目录，运行服务调用者程序：`./client -i test.conf`

## 配置文件

配置文件 `test.conf` 位于 bin 目录，包含以下配置项：

- **RPC服务端配置**：设置服务端 IP 和端口
- **ZooKeeper配置**：设置 ZooKeeper 服务器 IP 和端口

