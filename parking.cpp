// Smart Parking Management System - OOP Project
// Compile with: g++ -std=c++17 parking.cpp -o parking

#include <bits/stdc++.h>
using namespace std;
#include <ctime>

// ---------- Vehicle ----------
class Vehicle {
public:
    int id;
    string number, type;
    time_t entryTime, exitTime;

    Vehicle(int _id, string _number, string _type)
        : id(_id), number(_number), type(_type) {
        entryTime = time(nullptr);
    }
};

// ---------- Slot ----------
class Slot {
public:
    int slotId;
    bool isOccupied;

    Slot(int _id) : slotId(_id), isOccupied(false) {}
};

// ---------- Ticket ----------
class Ticket {
public:
    int ticketId;
    int vehicleId;
    int slotId;
    double amount;

    Ticket(int tId, int vId, int sId)
        : ticketId(tId), vehicleId(vId), slotId(sId), amount(0) {}
};

// ---------- ParkingLot ----------
class ParkingLot {
private:
    vector<Slot> slots;
    vector<Vehicle> vehicles;
    vector<Ticket> tickets;
    int nextVehicleId = 1;
    int nextTicketId = 1;

public:
    ParkingLot(int totalSlots) {
        for (int i = 1; i <= totalSlots; i++)
            slots.push_back(Slot(i));
    }

    // Park a vehicle
    int parkVehicle(string number, string type) {
        for (auto &slot : slots) {
            if (!slot.isOccupied) {
                slot.isOccupied = true;
                Vehicle v(nextVehicleId, number, type);
                vehicles.push_back(v);
                Ticket t(nextTicketId, v.id, slot.slotId);
                tickets.push_back(t);
                cout << "Vehicle parked. Ticket ID: " << nextTicketId
                     << ", Slot ID: " << slot.slotId << endl;
                nextVehicleId++;
                return nextTicketId++;
            }
        }
        cout << "Parking full! Cannot park vehicle." << endl;
        return -1;
    }

    // Exit a vehicle and calculate bill
    double exitVehicle(int ticketId) {
        auto tit = find_if(tickets.begin(), tickets.end(),
                           [ticketId](Ticket &t){ return t.ticketId == ticketId; });
        if (tit == tickets.end()) {
            cout << "Invalid Ticket ID!" << endl;
            return 0;
        }

        auto vit = find_if(vehicles.begin(), vehicles.end(),
                           [tit](Vehicle &v){ return v.id == tit->vehicleId; });

        if (vit == vehicles.end()) {
            cout << "Vehicle not found!" << endl;
            return 0;
        }

        // Calculate parking duration in hours
        vit->exitTime = time(nullptr);
        double hours = difftime(vit->exitTime, vit->entryTime) / 3600.0;
        double bill = max(1.0, hours) * 10; // $10 per hour minimum 1 hour
        tit->amount = bill;

        // Free the slot
        auto sit = find_if(slots.begin(), slots.end(),
                           [tit](Slot &s){ return s.slotId == tit->slotId; });
        if (sit != slots.end()) sit->isOccupied = false;

        cout << "Vehicle exited. Ticket ID: " << tit->ticketId
             << ", Bill: $" << bill << endl;
        return bill;
    }

    // Generate a report of parking lot
    void generateReport() {
        cout << "\n--- Parking Lot Report ---\n";
        cout << "Total Slots: " << slots.size() << "\n";
        int occupied = count_if(slots.begin(), slots.end(), [](Slot &s){ return s.isOccupied; });
        cout << "Occupied Slots: " << occupied << "\n";
        cout << "Available Slots: " << slots.size() - occupied << "\n";
        double totalEarnings = 0;
        for (auto &t : tickets) totalEarnings += t.amount;
        cout << "Total Earnings: $" << totalEarnings << "\n";

        cout << "\nCurrent Parked Vehicles:\n";
        for (auto &v : vehicles) {
            auto tit = find_if(tickets.begin(), tickets.end(), [v](Ticket &t){ return t.vehicleId == v.id && t.amount == 0; });
            if (tit != tickets.end())
                cout << "Vehicle ID: " << v.id << " | Number: " << v.number << " | Slot: " << tit->slotId << endl;
        }
        cout << "--------------------------\n";
    }
};

// ---------- Main Menu ----------
int main() {
    ParkingLot lot(5); // 5 slots for demo
    int choice;

    while (true) {
        cout << "\n1. Park Vehicle\n2. Exit Vehicle\n3. Generate Report\n4. Exit\nChoose option: ";
        cin >> choice;
        if (choice == 1) {
            string num, type;
            cout << "Enter Vehicle Number: "; cin >> num;
            cout << "Enter Vehicle Type: "; cin >> type;
            lot.parkVehicle(num, type);
        } else if (choice == 2) {
            int ticketId;
            cout << "Enter Ticket ID: "; cin >> ticketId;
            lot.exitVehicle(ticketId);
        } else if (choice == 3) {
            lot.generateReport();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
