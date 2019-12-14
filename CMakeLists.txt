cmake_minimum_required(VERSION 3.14)
project(ApacheLogAnalyzer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ApacheLogAnalyzer
        Document.h
        Log.h
        Request.h
        Document.cpp Log.cpp RequestData.h RequestVisitor.h HTTPRequestData.h ApplicationArguments.h DocumentHits.h LogManager.cpp LogManager.h FileManager.cpp FileManager.h LogFactory.cpp LogFactory.h Controller.cpp Controller.h Main.cpp)
