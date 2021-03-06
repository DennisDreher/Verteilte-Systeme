#include "lamport.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace Test;

int main(int argc, char **argv) {
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9093));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

lamportClient client(protocol);

  transport->open();
	client.lock();
	std::cout << "Ressource wird jetzt verwendet" << std::endl;
	sleep(5);
	client.unlock();
	std::cout << "Ressource ist wieder frei" << std::endl;
  transport->close();

  return 0;
}
