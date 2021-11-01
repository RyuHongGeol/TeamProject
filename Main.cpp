#include <iostream>
#include <chrono>
#include <string>
#include <thread>

void PrintMessage(const std::string& message, std::chrono::seconds delay)
{
	std::cout << "Sleep now...";

	auto end = std::chrono::high_resolution_clock::now() + delay;

	while (std::chrono::high_resolution_clock::now() < end)
	{
		std::this_thread::yield();
	}

	std::cout << message << std::endl;

}

int main()
{
	std::thread thread(PrintMessage, "Message From a child thread", std::chrono::seconds(3));
	
	PrintMessage("Message from a main thread",std::chrono::seconds(2));

	thread.join();

	std::cout<<"Add Something"<<std::endl;
	return 0;
}