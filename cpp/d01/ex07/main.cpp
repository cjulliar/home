#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
int main(int argc, char const *argv[])
{


	if (argc < 3)
	{
        std::cout << "Error format: ./Replace <file> \"str1\" \"str1\"" << std::endl;
		return(0);
	}


	ifstream fichier(argv[1], ios::in);  // on ouvre en lecture

	if(fichier)  // si l'ouverture a fonctionné
	{
		string ligne;
		while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
			if (ligne.find(argv[2]))
				cout << "yes" << endl;
			cout << ligne << endl;  // on l'affiche
		}
	}
	else
        std::cout << "Error format: ./Replace <file> \"str1\" \"str1\"" << std::endl;



	std::ofstream ofs("filename.replace");

	ofs << "truc a mettre dedans" << std::endl;

	ofs.close();
	return 0;
}