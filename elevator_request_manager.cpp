#include <iostream>
#include <set>
#include <string>
using namespace std;
class ElevatorRequestManager
{
private:
    set<int> requests;

public:
    void requestFloor(int floorNumber)
    {
        requests.insert(floorNumber);
        cout << "Floor " << floorNumber << " requested.\n";
    }
    void cancelRequest(int floorNumber)
    {
        if (requests.erase(floorNumber))
        {
            cout << "Request for floor" << floorNumber << "canceled.\n";
        }
        else
        {
            cout << "No such request to cancel.\n";
        }
    }
    bool isRequested(int floorNumber) const
    {
        return requests.find(floorNumber) != requests.end();
    }
    int pendingRequestsCount() const
    {
        return requests.size();
    }
    int nextFloor(int currentFloor)
    {
        if (requests.empty())
        {
            cout << "No pending requests.\n";
            return -1;
        }
        int closestFloor = *requests.begin();
        int minDistance = abs(currentFloor - closestFloor);

        for (int floor : requests)
        {
            int distance = abs(currentFloor - floor);
            if (distance < minDistance)
            {
                minDistance = distance;
                closestFloor = floor;
            }
        }
        requests.erase(closestFloor);
        return closestFloor;
    }

    void showRequests() const
    {
        if (requests.empty())
        {
            cout << "Mo pending requests.\n";
        }
        else
        {
            cout << "pending requests: ";
            for (int floor : requests)
            {
                cout << floor << " ";
            }
            cout << endl;
        }
    }
};

void showMenu()
{
    cout << "\n === Elevator Request Manager ===\n";
    cout << "1.Request Floor\n";
    cout << "2.Cancel Request\n";
    cout << "3.Check if Floor is Requested\n";
    cout << "4.Get Next Closest Floor\n";
    cout << "5.Show All Requests\n";
    cout << "6.Show Pending Request Count\n";
    cout << "7.Exit\n";
    cout << "Choose an option: ";
}

int main()
{
    ElevatorRequestManager manager;
    int choice, floor, currentFloor = 0;

    while (true)
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter floor to request: ";
            cin >> floor;
            manager.requestFloor(floor);
            break;

        case 2:
            cout << "Enter floor to cancel: ";
            cin >> floor;
            manager.requestFloor(floor);
            break;

        case 3:
            cout << "Enter floor to check: ";
            cin >> floor;
            if (manager.isRequested(floor))
            {
                cout << "Floor" << floor << "is requested.\n";
            }
            else
            {
                cout << "Floor" << floor << "is Not requested.\n";
            }
            break;

        case 4:
            cout << "Enter current floor: ";
            cin >> currentFloor;
            floor = manager.nextFloor(currentFloor);
            if (floor != -1)
            {
                cout << "Next closest floor to visit: " << floor << endl;
            }
            break;

        case 5:
            manager.showRequests();
            break;

        case 6:
            cout << "Pending request count: " << manager.pendingRequestsCount() << endl;
            break;

        case 7:
            cout << "Exiting.. the program has been successfully terminated\n";
            return 0;

        default:
            cout << "Invalid choice.Try again.\n";
        }
    }
    return 0;
}