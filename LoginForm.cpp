#include <iostream>
using namespace std;
#include <string>
#include <vector>
class User
{
private:
    string username, password;

public:
    User(string name, string pwd)
    {
        username = name;
        password = pwd;
    }

    void setUsername(string name)
    {
        username = name;
    }
    void setPassword(string pwd)
    {
        password = pwd;
    }
    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }
};

class userManager
{
private:
    vector<User> users;

public:
    void registerUser()

    {
        string username, password;
        cout << "Enter username:\n";
        cin >> username;
        cout << "Enter password:\n";
        cin >> password;
        User newUser(username, password);
        users.push_back(newUser);
        cout << "\t----User created successfully!!----" << endl;
    }

    void Login()
    {
        cout << "\n\n\t\tLogin Page" << endl;
        string usrname, password;
        cout << "Please enter your username:";
        cin >> usrname;
        int k = -1;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == usrname)
            {
                k = i;
                break;
            }
        }

        if (k != -1)
        {
            cout << "\nPlease enter your password:";
            cin >> password;
            if (users[k].getPassword() == password)
            {
                cout << "\n----Logged in successfully----" << endl;
            }
            else
            {
                cout << "\n!!!Password incorrect please try again!!!" << endl;
            }
        }
        else
        {
            cout << "\n!!!The user does not exist!!!" << endl;
        }
    }

    void userList()
    {
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << "." << users[i].getUsername() << endl;
        }
    }

    void userSearch()
    {
        string user;
        bool b = false;
        cout << "Please enter the username you want to search:" << endl;
        cin >> user;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == user)
            {
                cout << "\n----The user exists----" << endl;
                b = true;
                break;
            }
        }

        if (!b)
        {
            cout << "\n----The user does not exist----" << endl;
        }
    }

    void deleteUser()
    {
        string user;
        bool b = false;
        cout << "Please enter the username you want to delete:" << endl;
        cin >> user;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == user)
            {
                users.erase(users.begin() + i);
                b = true;
                cout << "----The user has been deleted successfully----" << endl;
                break;
            }
        }

        if (!b)
        {
            cout << "----The user does not exist----" << endl;
        }
    }
};

int main()
{
    cout << "\n\n\t--------------LOGIN FORM--------------" << endl;
    userManager usermanage;
    int op;
    bool con = false;
    char c;
    do
    {
        system("cls");
        cout << "\n\n\t\t1.Register User" << endl;
        cout << "\t\t2.Login" << endl;
        cout << "\t\t3.Show User List" << endl;
        cout << "\t\t4.Search User" << endl;
        cout << "\t\t5.Delete User" << endl;
        cout << "\t\t6.Exit" << endl;
        cout << "\n\n\t\tEnter your choice:";
        cin >> op;
        switch (op)
        {
        case 1:
            usermanage.registerUser();
            break;
        case 2:
            usermanage.Login();
            break;
        case 3:
            usermanage.userList();
            break;
        case 4:
            usermanage.userSearch();
            break;
        case 5:
            usermanage.deleteUser();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "!!!Please enter valid choice in range of 1 to 6!!!" << endl;
        }

        cout << "\nDo you want to continue?(Y/N):";
        cin >> c;
        if (c == 'y' || c == 'Y')
            con = true;
    } while (con);
    return 0;
}