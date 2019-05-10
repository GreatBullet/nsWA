   // not sucking Windows Activator, nsWA //
  //Does What it says or at least it will// Now it does :).
 //_____________________________________//  Greetings from GreatBullet //
// I developed this Program because Microsoft restricts my legal License after a Hardware change, and i am not willing to rebuild my old System, nor do i call the Hotline and waste my Time once again. 
#include <iostream>
#include <fstream>
#include <sstream>
void WriteHosts();
void ReadHosts();
int main(int argc, char** argv) {
	std::cout << "You have appended " << argc - 1
		<< " argument:";
	if (argc - 1 == 0) {
		std::cout << " -NONE" << std::endl;
		for (int i = 0; i < argc; ++i)
			std::cout << "Use the following Syntax \"" << argv[i] << " Windows-Serial\"\n";
	}
	else
	{
		std::cout << " " << argv[1];
		std::cout << "\n" << argv[0] << " " << argv[1];
		std::string CommandConcatinationVariable = "slmgr/ipk " + static_cast<std::string>(argv[1]);
		system(CommandConcatinationVariable.c_str());
		CommandConcatinationVariable = "slmgr /skms kms.digiboy.ir";
		system(CommandConcatinationVariable.c_str());
		CommandConcatinationVariable = "slmgr /ato";
		system(CommandConcatinationVariable.c_str());
		WriteHosts();
		ReadHosts();
	}

	return 0;
}
void WriteHosts() { // A Safety measure 
	std::string HostMod = "127.0.0.1 kms.digiboy.ir";
	std::fstream target("C:\\Windows\\System32\\drivers\\etc\\hosts", std::ios::app);
	target << "\n" << HostMod << "\n";
	target.close();
}
void ReadHosts() {
	std::string HostBuffer;
	std::ifstream filestream("C:\\Windows\\System32\\drivers\\etc\\hosts");
	if (filestream.is_open())
	{
		while (getline(filestream, HostBuffer))
		{
			std::cout << HostBuffer << std::endl;
		}
		filestream.close();
	}
	else {
		std::cout << "Error" << std::endl;
	}
}
