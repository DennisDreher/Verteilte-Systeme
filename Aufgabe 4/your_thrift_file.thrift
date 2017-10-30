#!/usr/local/bin/thrift -- gen cpp

namespace cpp Test

service time{
	void FileUpload(1: string fileText),
	i32 GetFileSize(),
	void FileUpload2(1: string fileText),
	i32 GetFileSize2(),
}
