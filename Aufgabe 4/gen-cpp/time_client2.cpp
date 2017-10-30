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
char * readed = new char[135];
int fileSize = 0;

  transport->open();
	fileSize = client.GetFileSize2();
	std::cout << "Gröse der Datei abgefragt" << std::endl;
  transport->close();

fup.open("Text2.txt", std::ios::in);
if(fileSize != 0)
{
	fup.seekg(fileSize);
}
while(!fup.eof())
{
std::memset(readed, 0, 135);
fup.read(readed, 135);

  transport->open();
	client.FileUpload2(readed);
  transport->close();
}
fup.close();
std::cout << "Datei vollständig hochgeladen" << std::endl;

  return 0;
}
