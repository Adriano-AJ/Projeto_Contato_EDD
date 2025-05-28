#include <iostream>
#include <locale.h>

using namespace std;

struct Data
{
   int dia;
   int mes;
   int ano;	
};

class Contato
{
	private:
		string email;
		string nome;
		string telefone;
		Data dtnasc;
	public:
		Contato() {
            this->email = "";
            this->nome = "";
            this->telefone = "";
            this->dtnasc = {1, 1, 2000};
        }
		Contato(string email, string nome, string telefone, Data dtnasc){
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = dtnasc;
		}	
		void setEmail(string email){
			this->email = email;
		}
		void setNome(string nome){
			this->nome = nome;
		}
		void setTelefone(string tel){
			this->telefone = tel;
		}
		void setDtNasc(Data dtnasc){
			this->dtnasc = dtnasc;
		}
		string getNome(){
			return this->nome;
		}
		string getEmail(){
			return this->email;
		}
		string getTelefone(){
			return this->telefone;
		}
		Data getDtNasc(){
			return this->dtnasc;
		}
		int idade(){
		    Data hoje;
		    hoje.ano = 2025;
		    int idadeAtual = hoje.ano - dtnasc.ano; // corrigido!
		    return idadeAtual;
		}
		
};

int main(int argc, char** argv)
{
	Contato contatos[5];

    // Entrada de dados
    for (int i = 0; i < 5; i++) {
        cout << "\nDigite os dados do contato " << (i + 1) << endl;

        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Data de nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;
        cin.ignore();  // Limpar o buffer do '\n'

        Data dataNasc;
        dataNasc.dia = dia;
        dataNasc.mes = mes;
        dataNasc.ano = ano;
        
        Contato c(email, nome, telefone, dataNasc);
        contatos[i] = c;
    }

    // Exibir dados
    cout << "\n--- Contatos cadastrados ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "Contato " << (i + 1) << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos\n";
        cout << "--------------------------\n";
    }

    return 0;
}