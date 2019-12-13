cmake_minimum_required(VERSION 3.14)
project(ApacheLogAnalyzer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ApacheLogAnalyzer
        Document.h
        DocumentImpl.cpp
        FileAnalyzerService.h
        FileAnalyzerServiceImpl.cpp
        FileManager.cpp
        FileManagerService.h
        Log.h
        LogAnalyzerService.h
        LogAnalyzerServiceImpl.cpp
        LogFactory.h
        LogImpl.cpp
        Main.h
        MainImpl.cpp
        Request.h
        RequestImpl.cpp)
