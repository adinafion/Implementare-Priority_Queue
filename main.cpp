#include <iostream>

class PRIORITY_QUEUE
{
private:
	int size;
	int* data;
public:

	PRIORITY_QUEUE(int size)
	{
		this->size = size;
		data = new int[this->size];
	}

	void insert(int key)
	{
		int* new_data = new int[size + 1];

		for (int i = 0; i < size; i++)
			new_data[i] = data[i];

		new_data[size] = key;
		size = size + 1;

		delete[] data;
		data = new_data;

		increase_key(size - 1, key);
	}

	void extract_max()
	{
		data[0] = data[size - 1];
		size = size - 1;
		max_heapfy(0);
	}

	int max_element()
	{
		return data[0];
	}

	void increase_key(int i, int key)
	{
		if (key > data[i])
		{
			data[i] = key;
			int p = (i - 1) / 2;
			while (i > 0 && data[p] < key)
			{
				data[i] = data[p];
				i = p;
				p = (i - 1) / 2;
			}
			data[i] = key;
		}
	}

	void max_heapfy(int i)
	{
		int st, dr, imax = i;
		st = 2 * i + 1;
		dr = 2 * i + 2;

		if (st<size && data[st]>data[imax])
			imax = st;
		if (dr<size && data[dr]>data[imax])
			imax = dr;

		if (imax != i)
		{
			std::swap(data[i], data[imax]);
			max_heapfy(imax);
		}
	}

	void afisare()
	{
		for (int i = 0; i < size; i++)
			std::cout << data[i] << " ";
	}

	~PRIORITY_QUEUE()
	{
		delete[] data;
	}

};

int main()
{
	PRIORITY_QUEUE coada(0);

	std::cout << " MENIU \n";
	std::cout << "0. EXIT\n";
	std::cout << "1. Insereaza un nou nod in coada\n";
	std::cout << "2. Extrage elementul de prioritate maxima\n";
	std::cout << "3. Returneaza elementul de prioritate maxima\n";
	std::cout << "4. Afisare elemente din coada\n";
	std::cout << "5. Afisare meniu.\n";
	std::cout << "Optiunea dumneavoastra este: ";

	int choice;

	std::cin >> choice;

	while (choice)
	{
		switch (choice)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			int nr;
			std::cout << "Introduceti valoarea pe care doriti sa o inserati: ";
			std::cin >> nr;
			coada.insert(nr);
			std::cout << "\nValoarea data a fost inserata cu succes!\n";
			std::cout << "Optiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		case 2:
		{
			coada.extract_max();
			std::cout << "Elementul de prioritate maxima a fost extras cu succes!\n";
			std::cout << "Optiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		case 3:
		{
			std::cout << "Elementul de prioritate maxima este: " << coada.max_element() << '\n';
			std::cout << "Optiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		case 4:
		{
			std::cout << "Elementele din coada sunt: ";
			coada.afisare();
			std::cout << "\nOptiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		case 5:
		{
			std::cout << " MENIU \n";
			std::cout << "0. EXIT\n";
			std::cout << "1. Insereaza un nou nod in coada\n";
			std::cout << "2. Extrage elementul de prioritate maxima\n";
			std::cout << "3. Returneaza elementul de prioritate maxima\n";
			std::cout << "4. Afisare elemente din coada\n";
			std::cout << "5. Afisare meniu.\n";
			std::cout << "Optiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		default:
		{
			std::cout << "\nOptiunea aleasa nu este valabila. Incercati din nou.";
			std::cout << "\nOptiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		}

	}
	return 0;
}