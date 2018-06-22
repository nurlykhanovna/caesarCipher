/*
 * Caesar cipher
 @author Alima
 */
#include <iostream>
#include <string>

using namespace std;

int main(){

	cout << "The first part of the program (encryption)."<<endl;

	string word = "";
	cout << "Please enter the word that you want to encrypt: ";
	cin >> word;

	int key;
	cout << "Please enter the number that you want to use as the key for encryption: ";
	cin >> key;

	string cipher = "";
	cout << "Please enter the word that you want to use as the cipher for encryption: ";
	cin >> cipher;

	string a = "abcdefghijklmnopqrstuvwxyz";
	string b = "                          ";

	for (int i = 0; i < 26; i++) {
		b[(key+i)%26] = a[i];
		}

	for (int i = 0; i < cipher.size(); i++) {
		for (int j = i+1; j < cipher.size(); j++){
			if (cipher[i] == cipher[j]) {
				cipher.erase(j,1);
				}
		}
	}

	b.insert(key,cipher);
	for (int i = 0; i < b.size(); i++) {
		for (int j = i + 1; j < b.size(); j++) {
			if (b[i] == b[j]) b.erase(j,1);
		}
	}

	for (int i = 0; i < word.size(); i++) {
	for (int j = 0; j < 26; j++) {
		if (word[i] == a[j]) {
			word[i] = b[j];
			break;
			}
		}
	}

	cout << "The encrypted message: " << word << endl;

	cout << "The second part of the program (decryption)."<<endl;

	string wor = "";
	cout << "Please enter the word that you want to decrypt: ";
	cin >> wor;

	int ke;
	cout << "Please enter the number that you want to use as the key for decryption: ";
	cin >> ke;

	string ciphe = "";
	cout << "Please enter the word that you want to use as the cipher for decryption: ";
	cin >> ciphe;

	string d = "                                                                      ";

	for (int i = 0; i < 26; i++) {
	d[(ke+i)%26] = a[i];
	}

	for (int i = 0; i < ciphe.size(); i++) {
	for (int j = i+1; j < ciphe.size(); j++){
		if (ciphe[i] == ciphe[j]) {
			ciphe.erase(j,1);
			}
		}
	}	
	d.insert(ke,ciphe);
	for (int i = 0; i < d.size(); i++) {
		for (int j = i + 1; j < d.size(); j++) {
			if (d[i] == d[j]) d.erase(j,1);
			}
	}

	for (int i = 0; i < wor.size(); i++) {
		for (int j = 0; j < 26; j++) {
		if (wor[i] == d[j]) {
			wor[i] = a[j];
			break;
			}
		}
	}

	cout << "The decrypted message: " << wor << endl;
return 0;
}
