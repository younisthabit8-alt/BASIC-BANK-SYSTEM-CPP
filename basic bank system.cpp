#include <iostream>
#include <vector>

using namespace std;

class clsPerson
{
protected:

    string _Name;
    string _Phone;

public:

    void SetName(string Name)
    {
        _Name = Name;
    }

    string GetName()
    {
        return _Name;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string GetPhone()
    {
        return _Phone;
    }
};

class clsClient : public clsPerson
{
private:

    string _AccountNumber;
    double _Balance;

public:

    void SetAccountNumber(string AccountNumber)
    {
        _AccountNumber = AccountNumber;
    }

    string GetAccountNumber()
    {
        return _AccountNumber;
    }

    void SetBalance(double Balance)
    {
        _Balance = Balance;
    }

    double GetBalance()
    {
        return _Balance;
    }

    void ReadClientInfo()
    {
        cout << "Enter Account Number: ";
        cin >> _AccountNumber;

        cout << "Enter Name: ";
        cin >> _Name;

        cout << "Enter Phone: ";
        cin >> _Phone;

        cout << "Enter Balance: ";
        cin >> _Balance;
    }

    void PrintClientInfo()
    {
        cout << "\nAccount Number: " << _AccountNumber << endl;
        cout << "Name: " << _Name << endl;
        cout << "Phone: " << _Phone << endl;
        cout << "Balance: " << _Balance << endl;
    }
};

vector<clsClient> vClients;

void AddClient()
{
    clsClient Client;

    Client.ReadClientInfo();

    vClients.push_back(Client);

    cout << "\nClient Added Successfully\n";
}

void ShowClients()
{
    if (vClients.size() == 0)
    {
        cout << "\nNo Clients Found\n";
        return;
    }

    cout << "\nClients List\n";

    for (clsClient Client : vClients)
    {
        Client.PrintClientInfo();

        cout << "----------------------\n";
    }
}

void FindClient()
{
    string AccountNumber;

    cout << "Enter Account Number: ";
    cin >> AccountNumber;

    for (clsClient Client : vClients)
    {
        if (Client.GetAccountNumber() == AccountNumber)
        {
            cout << "\nClient Found\n";

            Client.PrintClientInfo();

            return;
        }
    }

    cout << "\nClient Not Found\n";
}

void DeleteClient()
{
    string AccountNumber;

    cout << "Enter Account Number To Delete: ";
    cin >> AccountNumber;

    for (int i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].GetAccountNumber() == AccountNumber)
        {
            vClients.erase(vClients.begin() + i);

            cout << "\nClient Deleted Successfully\n";

            return;
        }
    }

    cout << "\nClient Not Found\n";
}

void Deposit()
{
    string AccountNumber;
    double Amount;

    cout << "Enter Account Number: ";
    cin >> AccountNumber;

    for (clsClient& Client : vClients)
    {
        if (Client.GetAccountNumber() == AccountNumber)
        {
            cout << "Enter Deposit Amount: ";
            cin >> Amount;

            Client.SetBalance(Client.GetBalance() + Amount);

            cout << "\nDeposit Done Successfully\n";

            cout << "New Balance = "
                 << Client.GetBalance() << endl;

            return;
        }
    }

    cout << "\nClient Not Found\n";
}

void Withdraw()
{
    string AccountNumber;
    double Amount;

    cout << "Enter Account Number: ";
    cin >> AccountNumber;

    for (clsClient& Client : vClients)
    {
        if (Client.GetAccountNumber() == AccountNumber)
        {
            cout << "Enter Withdraw Amount: ";
            cin >> Amount;

            if (Amount > Client.GetBalance())
            {
                cout << "\nNot Enough Balance\n";
                return;
            }

            Client.SetBalance(Client.GetBalance() - Amount);

            cout << "\nWithdraw Done Successfully\n";

            cout << "New Balance = "
                 << Client.GetBalance() << endl;

            return;
        }
    }

    cout << "\nClient Not Found\n";
}

void CurrencyExchange()
{
    short Choice;
    double Amount;

    cout << "\n========== Currency Exchange ==========\n";

    cout << "1 - USD To YER\n";
    cout << "2 - SAR To YER\n";
    cout << "3 - USD To SAR\n";

    cout << "\nChoose Option: ";
    cin >> Choice;

    cout << "Enter Amount: ";
    cin >> Amount;

    switch (Choice)
    {
    case 1:
    {
        double Result = Amount * 1558;

        cout << "\n" << Amount
             << " USD = "
             << Result
             << " YER\n";

        break;
    }

    case 2:
    {
        double Result = Amount * 410;

        cout << "\n" << Amount
             << " SAR = "
             << Result
             << " YER\n";

        break;
    }

    case 3:
    {
        double Result = Amount * 3.75;

        cout << "\n" << Amount
             << " USD = "
             << Result
             << " SAR\n";

        break;
    }

    default:
        cout << "\nInvalid Choice\n";
    }
}

void MainMenu()
{
    short Choice;

    do
    {
        cout << "\n========== Bank System ==========\n";

        cout << "1 - Show Clients\n";
        cout << "2 - Add Client\n";
        cout << "3 - Find Client\n";
        cout << "4 - Delete Client\n";
        cout << "5 - Deposit\n";
        cout << "6 - Withdraw\n";
        cout << "7 - Currency Exchange\n";
        cout << "8 - Exit\n";

        cout << "\nChoose Option: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            ShowClients();
            break;

        case 2:
            AddClient();
            break;

        case 3:
            FindClient();
            break;

        case 4:
            DeleteClient();
            break;

        case 5:
            Deposit();
            break;

        case 6:
            Withdraw();
            break;

        case 7:
            CurrencyExchange();
            break;

        case 8:
            cout << "\nProgram Ended\n";
            break;

        default:
            cout << "\nInvalid Choice\n";
        }

    } while (Choice != 8);
}

int main()
{
    MainMenu();

    return 0;
}