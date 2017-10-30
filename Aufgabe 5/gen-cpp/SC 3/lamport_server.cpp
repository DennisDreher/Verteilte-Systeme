// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "lamport.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/concurrency/PlatformThreadFactory.h>

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::Test;

using namespace apache::thrift::concurrency;

int lt = 0;
int queue[50];
int counter = 0;
int counter2 = 0;
int status = 0;
int status2 = 0;

class lamportHandler : virtual public lamportIf {
 public:
  lamportHandler() {
    // Your initialization goes here
  }

  void lock() {
    // Your implementation goes here
	lt++;
	std::cout << "Lamporttime = " << lt << std::endl;	
	std::cout << "Requestanfrage" << std::endl;
					//ändern
	SOCKET2;
	TRANSPORT2;
	PROTOCOL2;
	CLIENT2;
	transport2->open();
	status = client2.request(lt, MY_CLIENT);
	/*if (status <= lt)
		lt++;
	else
		lt = status;*/
	transport2->close();

	SOCKET1;
	TRANSPORT1;
	PROTOCOL1;
	CLIENT1;
	transport1->open();
	status2 = client1.request(lt, MY_CLIENT);
	/*if (status <= lt)
		lt++;
	else
		lt = status;*/
	transport1->close();

	
	
	if (status <= lt)
		lt++;
	else
		lt = status;

	std::cout << "Lamporttime = " << lt << std::endl;

	if (status2 <= lt)
		lt++;
	else
		lt = status;

	std::cout << "Lamporttime = " << lt << std::endl;

	queue[counter] = MY_CLIENT;
	counter++;

	for(int i = 0; i < counter; i++)
	{
		std::cout << i << ". Zugriff: " << queue[i] << std::endl;
	}
	
	if (queue[counter2] != MY_CLIENT)
		std::cout << "Ressource ist noch nicht frei" << std::endl;
	while(queue[counter2] != MY_CLIENT)
	{};
	std::cout << "Ressource wird jetzt verwendet" << std::endl;	
  }

  void unlock() {
    // Your implementation goes here
	SOCKET2;
	TRANSPORT2;
	PROTOCOL2;
	CLIENT2;
	transport2->open();
		client2.release(lt);
	transport2->close();

	SOCKET1;
	TRANSPORT1;
	PROTOCOL1;
	CLIENT1;
	transport1->open();
		client1.release(lt);
	transport1->close();

	counter2++;
	std::cout << "Ressource ist wieder frei" << std::endl;
  }

  int32_t request(const int32_t ts, const int32_t wclient) {
    // Your implementation goes here
	lt = ts + 1;
	std::cout << "Lamporttime = " << lt << std::endl;
	queue[counter] = wclient;			//ändern
	counter++;
	for(int i = 0; i < counter; i++)
	{
		std::cout << i << ". Zugriff: " << queue[i] << std::endl;
	}
	return lt;
  }

  void release(const int32_t ts) {
    // Your implementation goes here
	lt = ts + 1;
	std::cout << "Lamporttime = " << lt << std::endl;
	counter2++;
	std::cout << "Ressource ist wieder frei" << std::endl;
  }

  void servercommunication() {
    // Your implementation goes here
    printf("servercommunication\n");
  }

};

int main(int argc, char **argv) {
  int port = 9093;
  shared_ptr<lamportHandler> handler(new lamportHandler());
  shared_ptr<TProcessor> processor(new lamportProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(10);
  shared_ptr<ThreadFactory> threadFactory(new PosixThreadFactory());

  threadManager->threadFactory(threadFactory);

  threadManager->start();

  TServer* server = NULL;

  server = new TThreadedServer(processor, serverTransport, transportFactory, protocolFactory);
server->serve();
  return 0;
}

