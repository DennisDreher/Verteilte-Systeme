#!/usr/local/bin/thrift -- gen cpp

namespace cpp Test

service lamport{
	void lock(),
	void unlock(),
	i32 request(1: i32 ts, 2: i32 wclient),
	void release(1: i32 ts),
	void servercommunication()
}
