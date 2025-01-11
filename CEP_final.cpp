#include <iostream>
#include <conio.h>
using namespace std;

struct Machines {
    int machineId ;
    string machineName;
    string machineType;
    bool operationStatus;
    bool maintenanceStatus; 
};

Machines machine[50];
int total = 0;

void enter() {
    int choice;
    cout << "How many machine entries would you like to input? ";
    cin >> choice;

    if (total + choice > 50) {
        cout << "Cannot add more than 50 machines!" << endl;
        return;
    }

    if (total == 0) {
        total = choice;
        for (int i = 0; i < choice; i++) {
            cout << "\nEnter data of machine " << i + 1 << ": " << endl;
            cout << "\nEnter Machine ID: ";
            cin >> machine[i].machineId;
            cin.ignore();
            cout << "Enter Machine Name: ";
            getline(cin, machine[i].machineName);
            cout << "Enter Machine Type: ";
            getline(cin, machine[i].machineType);
            cout << "Enter Operation status of machine"<<endl;
            cout << "Press 1 for Running / Press 0 for not running: ";
            cin >> machine[i].operationStatus;
            cout << "Is maintenance required? "<<endl;
            cout << "Press 1 for YES / Press 0 for NO: ";
            cin >> machine[i].maintenanceStatus;
        }
    } else {
        for (int i = total; i < total + choice; i++) {
            cout << "\nEnter data of machine " << i + 1 << ": " << endl;
            cout << "\nEnter Machine ID: ";
            cin >> machine[i].machineId;
            cin.ignore();
            cout << "Enter Machine Name: ";
            getline(cin, machine[i].machineName);
            cout << "Enter Machine Type: ";
            getline(cin, machine[i].machineType);
            cout << "Enter Operation status of machine"<<endl;
            cout << "Press 1 for Running / Press 0 for not running: ";
            cin >> machine[i].operationStatus;
            cout << "Is maintenance required? "<<endl;
            cout << "Press 1 for YES / Press 0 for NO: ";
            cin >> machine[i].maintenanceStatus;
        }
        total = total + choice;
    }
}

void show() {
    if (total == 0) {
        cout << "\nNo Data!" << endl;
    } else {
        for (int i = 0; i < total; i++) {
            cout << "\nData of machine: " << i + 1 << "\n\n";
            cout << "Machine ID: " << machine[i].machineId << endl;
            cout << "Machine Name: " << machine[i].machineName << endl;
            cout << "Machine Type: " << machine[i].machineType << endl;
            if (machine[i].operationStatus == 1){
                cout << "Operation Status: Running"<< endl;
            }
            else{
                cout << "Operation Status: Not Running"<< endl;
            }
            if (machine[i].maintenanceStatus == 1){
                cout << "Maintenance Required?  YES"<< endl;
            }
            else{
                cout << "Maintenance Required?  NO"<< endl;
            }
        }
    }
}

void search() {
    if (total == 0) {
        cout << "No Data!" << endl;
    } else {
        int machID;
        cout << "\nEnter Machine ID of the machine you want to search: ";
        cin >> machID;

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (machID == machine[i].machineId) {
                cout << "\nData of Machine:\n";
                cout << "Machine ID: " << machine[i].machineId << endl;
                cout << "Machine Name: " << machine[i].machineName << endl;
                cout << "Machine Type: " << machine[i].machineType << endl;
                if(machine[i].operationStatus == 1){
                    cout << "Operation Status: Running"<<endl;
                }
                else{
                    cout << "Operation Status: Not Running"<<endl;
                }
                if(machine[i].maintenanceStatus == 1){
                    cout << "Maintenance Required: YES"<<endl;
                }
                else{
                    cout << "Maintanence Required: NO"<<endl;
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nNo machine found with machine ID " << machID << endl;
        }
    }
}

void update() {
    if (total == 0) {
        cout << "No Data!" << endl;
    } else {
        int machID;
        cout << "\nEnter Machine ID of machine which you want to Update: ";
        cin >> machID;
        bool found = false;
        for (int i = 0; i < total; i++) {
            if (machID == machine[i].machineId) {
                cout << "Previous Data of the machine: " << endl << endl;
                cout << "Machine ID: " << machine[i].machineId << endl;
                cout << "Machine Name: " << machine[i].machineName << endl;
                cout << "Machine Type: " << machine[i].machineType << endl;
                if(machine[i].operationStatus == 1){
                cout << "Operation Status: Running"<< endl;
                }
                else{
                cout << "Operation Status: Not Running"<< endl;
                }
                if(machine[i].maintenanceStatus == 1){
                cout << "Maintanance Required? YES"<< endl;
                }
                else{
                cout << "Maintanance Required? NO"<< endl;
                }

                cout << "\nEnter new data: " << endl << endl;
                cout << "Machine ID: ";
                cin >> machine[i].machineId;
                cin.ignore();
                cout << "Machine Name: ";
                getline(cin, machine[i].machineName);
                cout << "Machine Type: ";
                getline(cin, machine[i].machineType);
                cout << "Operation Status: "<<endl;
                cout << "Press 1 for Running / Press 0 for not running: ";
                cin >> machine[i].operationStatus;
                cout << "Is Maintenance Required? "<<endl;
                cout << "Press 1 for YES / Press 0 for NO: ";
                cin >> machine[i].maintenanceStatus;
            
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No Machine found with machine ID: " << machID << endl;
        }
    }
}

void deleteRecord() {
    if (total == 0) {
        cout << "No Data!" << endl;
    } else {
        int x;
        cout << "Press 1 to delete all data records." << endl;
        cout << "Press 2 to delete specific data record." << endl;
        cin >> x;

        if (x == 1) {
            int choice;
            cout<<"\nAre you sure you want to delete ALL data records?"<<endl;
            cout<<"Press 1 for YES / Press 0 for NO"<<endl;
            cin>>choice;
            if(choice == 1){
                total = 0;
                cout << "\nAll data records DELETED!" <<endl;
            }
        } else if (x == 2) {
            int machID;
            cout << "Enter machine ID of the machine whose data you want to delete: ";
            cin >> machID;
            for (int i = 0; i < total; i++) {
                if (machID == machine[i].machineId) {
                    for (int j = i; j < total - 1; j++) {
                        machine[j] = machine[j + 1];
                    }
                    total--;
                    cout << "Data of machine " << machID << " has been removed." << endl;
                    break;
                }
            }
        } else {
            cout << "Invalid Input!" << endl;
        }
    }
}

int main() {
    // int value;
    char value;
    cout << "\nIndustrial Equipment Monitoring System." << endl;

    while (true) {
        cout << "\nPress 1 to Enter data" << endl;
        cout << "Press 2 to Show data" << endl;
        cout << "Press 3 to Search data" << endl;
        cout << "Press 4 to Update data" << endl;
        cout << "Press 5 to Delete data" << endl;
        cout << "Press 6 to Exit." << endl;
        cout<<"Your choice: ";
        value = getche();
        cout<<endl;

        switch (value) {
            case '1':
                enter();
                break;
            case '2':
                show();
                break;
            case '3':
                search();
                break;
            case '4':
                update();
                break;
            case '5':
                deleteRecord();
                break;
            case '6':
                cout<<"Exiting Program..."<<endl;
                exit(0);
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
    return 0;
}