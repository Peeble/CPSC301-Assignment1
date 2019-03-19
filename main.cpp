#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


using namespace std;


struct person {
    char name[20];
    float balance;
};

int lines()
{
    int N = 0;
    string line;
    ifstream data("data.txt");
    while(getline(data,line))
    {
        N++;
    }
    cout << "Number of lines: " << N << endl;
    data.close();
    return N;
}

void Display(string a[][2], int N)
{
    cout << "    " << "Name" << "      " << "Balance" << endl << "---------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << "    ";
        }
        cout << endl;
    }
}
void FindRichest(string a[][2], int N)
{
    double temp = 0;
    string name;

    for (int i = 0; i < N;i++)
    {
        double balance = stod(a[i][1]);
        if(balance > temp){
            temp = balance;
            name = a[i][0];

        }
    }
    cout << "Highest value is " << name << " with " << temp << endl;

}

void Deposit(string custName, string a[][2], int N)
{
    double deposit;
    double newbal;
    for (int i = 0; i < N; i++) {
        if (custName == a[i][0]) {
            cout << "enter how much to deposit" << endl;
            cin >> deposit;

            newbal = stod(a[i][1]) + deposit;



            cout << "new balance is " << newbal;

            a[i][1] = to_string(newbal);
        }
    }
}

void NewCopy(string filename, string a[][2], int N)
{
    ofstream data(filename);
    if (data.is_open())
    {

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                data << a[i][j] << " ";
            }
            data << endl;
        }

    }
    data.close();
}

int main() {
    int N = lines();
    string firstname;
    string lastname;
    string fullname;
    double balance;
    string custName;

    string a[N][2];

    person p[N];

    ifstream data("data.txt");

    if (data.is_open())


    {
        for (int i = 0; i < N; i++){

            data >> firstname >> lastname >> p[i].balance;

            fullname = firstname + " " + lastname;

            strcpy(p[i].name,fullname.c_str());
        }

        for (int j = 0; j < N; j++){
            a[j][0] = p[j].name;
            a[j][1] = to_string(p[j].balance);
        }

        Display(a, N);
        FindRichest(a, N);

        cout << "enter customer name" << endl;
        getline(cin,custName);
        Deposit(custName, a, N);
        NewCopy("data.txt", a, N);



    }

    else
        cout << "no work";





    data.close();
}
