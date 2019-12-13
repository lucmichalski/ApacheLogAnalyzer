cmake_minimum_required(VERSION 3.14)
project(ApacheLogAnalyzer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ApacheLogAnalyzer
        Document.h
        FileAnalyzerService.h
        FileAnalyzerServiceImpl.cpp
        FileManager.cpp
        FileManagerService.h
        Log.h
        LogAnalyzerService.h
        LogAnalyzerServiceImpl.cpp
        LogFactory.h
        Main.h
        MainImpl.cpp
        Request.h
        Request.cpp Document.cpp Log.cpp)
