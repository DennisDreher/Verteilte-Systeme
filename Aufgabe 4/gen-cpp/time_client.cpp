#include "time.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace Test;

int main(int argc, char **argv) {
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 12345));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

timeClient client(protocol);

std::fstream fup;
char * readed = new char[100];
int fileSize = 0;

  transport->open();
	fileSize = client.GetFileSize();
	std::cout << "Gröse der Datei abgefragt" << std::endl;
  transport->close();

fup.open("Text.txt", std::ios::in);
if(fileSize != 0)
{
	fup.seekg(fileSize);
}
while(!fup.eof())
{
std::memset(readed, 0, 100);
fup.read(readed, 100);

  transport->open();
	client.FileUpload(readed);
  transport->close();
}
fup.close();
std::cout << "Datei vollständig hochgeladen" << std::endl;

  return 0;
}
