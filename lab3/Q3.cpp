#include <iostream>
#include <string>
using namespace std;

struct Passenger {
    string name;
    Passenger* next;
    Passenger(string n) {
        name = n;
        next = NULL;
    }
};

struct Flight {
    string flightNo;
    Passenger* passengers;
    Flight* next;
    Flight(string f) {
        flightNo = f;
        passengers = NULL;
        next = NULL;
    }
};

class ReservationSystem {
public:
    Flight* flights;

    ReservationSystem() {
        flights = NULL;
    }

    // Add new flight
    void addFlight(string flightNo) {
        Flight* temp = flights;
        while (temp != NULL) {
            if (temp->flightNo == flightNo) {
                cout << "Flight already exists!\n";
                return;
            }
            temp = temp->next;
        }
        Flight* newFlight = new Flight(flightNo);
        newFlight->next = flights;
        flights = newFlight;
        cout << "Flight " << flightNo << " added.\n";
    }

    // Reserve a ticket
    void reserveTicket(string flightNo, string name) {
        Flight* flight = findFlight(flightNo);
        if (flight == NULL) {
            cout << "Flight not found!\n";
            return;
        }
        Passenger* newP = new Passenger(name);

        if (flight->passengers == NULL || name < flight->passengers->name) {
            newP->next = flight->passengers;
            flight->passengers = newP;
            cout << "Ticket reserved for " << name << " on flight " << flightNo << endl;
            return;
        }

        Passenger* curr = flight->passengers;
        while (curr->next != NULL && curr->next->name < name) {
            curr = curr->next;
        }
        if (curr->name == name || (curr->next != NULL && curr->next->name == name)) {
            cout << "Passenger already reserved!\n";
            delete newP;
            return;
        }
        newP->next = curr->next;
        curr->next = newP;
        cout << "Ticket reserved for " << name << " on flight " << flightNo << endl;
    }

    // Cancel a ticket
    void cancelTicket(string flightNo, string name) {
        Flight* flight = findFlight(flightNo);
        if (flight == NULL || flight->passengers == NULL) {
            cout << "Reservation not found.\n";
            return;
        }

        Passenger* curr = flight->passengers;
        if (curr->name == name) {
            flight->passengers = curr->next;
            delete curr;
            cout << "Cancelled reservation for " << name << endl;
            return;
        }

        while (curr->next != NULL && curr->next->name != name) {
            curr = curr->next;
        }

        if (curr->next == NULL) {
            cout << "Reservation not found.\n";
        } else {
            Passenger* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            cout << "Cancelled reservation for " << name << endl;
        }
    }

    // Check reservation
    void checkReservation(string flightNo, string name) {
        Flight* flight = findFlight(flightNo);
        if (flight == NULL) {
            cout << "Flight not found!\n";
            return;
        }
        Passenger* curr = flight->passengers;
        while (curr != NULL) {
            if (curr->name == name) {
                cout << name << " has a reservation on flight " << flightNo << endl;
                return;
            }
            curr = curr->next;
        }
        cout << name << " does not have a reservation.\n";
    }

    // Show passengers
    void showPassengers(string flightNo) {
        Flight* flight = findFlight(flightNo);
        if (flight == NULL) {
            cout << "Flight not found!\n";
            return;
        }
        if (flight->passengers == NULL) {
            cout << "No passengers on flight " << flightNo << endl;
            return;
        }
        cout << "Passengers on flight " << flight->flightNo << ":\n";
        Passenger* curr = flight->passengers;
        while (curr != NULL) {
            cout << "- " << curr->name << endl;
            curr = curr->next;
        }
    }

    // Show all flights
    void showFlights() {
        if (flights == NULL) {
            cout << "No flights available.\n";
            return;
        }
        cout << "Flights available:\n";
        Flight* curr = flights;
        while (curr != NULL) {
            cout << "- " << curr->flightNo << endl;
            curr = curr->next;
        }
    }

private:
    Flight* findFlight(string flightNo) {
        Flight* curr = flights;
        while (curr != NULL) {
            if (curr->flightNo == flightNo) return curr;
            curr = curr->next;
        }
        return NULL;
    }
};

int main() {
    ReservationSystem rs;
    int choice;
    string flightNo, name;

    do {
        cout << "\n--- Airline Reservation Menu ---\n";
        cout << "1. Add Flight\n";
        cout << "2. Reserve Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Check Reservation\n";
        cout << "5. Show Passengers of Flight\n";
        cout << "6. Show Flights\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter flight number: ";
            getline(cin, flightNo);
            rs.addFlight(flightNo);
        } else if (choice == 2) {
            cout << "Enter flight number: ";
            getline(cin, flightNo);
            cout << "Enter passenger name: ";
            getline(cin, name);
            rs.reserveTicket(flightNo, name);
        } else if (choice == 3) {
            cout << "Enter flight number: ";
            getline(cin, flightNo);
            cout << "Enter passenger name: ";
            getline(cin, name);
            rs.cancelTicket(flightNo, name);
        } else if (choice == 4) {
            cout << "Enter flight number: ";
            getline(cin, flightNo);
            cout << "Enter passenger name: ";
            getline(cin, name);
            rs.checkReservation(flightNo, name);
        } else if (choice == 5) {
            cout << "Enter flight number: ";
            getline(cin, flightNo);
            rs.showPassengers(flightNo);
        } else if (choice == 6) {
            rs.showFlights();
        } else if (choice == 7) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
