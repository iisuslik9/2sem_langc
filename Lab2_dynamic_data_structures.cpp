//������� 4
//��������� ���������, ������� �������� ������� ���������� � ������� ��
//����������.
//������ ������ �������� :
//� ����� ����������;
//� ����� �����;
//� ������� � �������� ���������;
//� �������� ���� ������.
//��������� ������ ������������ :
//� �������� ���� ������ � ���� ��������� ������;
//� ���������� � �������� ������;
//� �� ��������� ������ ����� � ���� ������ ����� ������ � �� �����������
//���������;
//� ����� ���� ������

#include <iostream>
using namespace std;

struct TicketRequest {
    string destination;
    string flight_num;
    string pass_name;
    string date;
    
    TicketRequest(const string& dest, const string& num, const string& name, const string& date) : destination(dest), flight_num(num), pass_name(name), date(date) {}
};
 
struct NodeT {
    TicketRequest data;
    NodeT* left;
    NodeT* right;
    NodeT(const TicketRequest& data) : data( data), left(nullptr), right(nullptr) {}
};

struct BinaryTree {
    NodeT* root;

    BinaryTree() : root(nullptr) {}

    BinaryTree(const TicketRequest& ticket)
    {
        NodeT* node = new NodeT(ticket);
        root = node;
    }
    ~BinaryTree()
    {
        if (root != nullptr) {
            Destroy(root);

            cout << "������ �������!\n";
        }
        else {
            cout << "������ ������!\n";
        }
    }

    void Destroy(NodeT* node)
    {
        if (node != nullptr)
        {
            Destroy(node->left);
            Destroy(node->right);
            delete node;
        }
    }
    NodeT* insert(NodeT* node, const TicketRequest& ticket) {
        if (node == nullptr) {
            return new NodeT(ticket);
        }
        else if (compareTickets(ticket, node->data)) {
            node->left = insert(node->left, ticket);
        }
        else if (compareTickets(node->data, ticket)) {
            node->right = insert(node->right, ticket);
        }
        else {
            cout << "������ ��� ��������� " + ticket.flight_num + " " + ticket.date + " �� ��� " + ticket.pass_name <<endl;
        }
        return node;
    }

    void insert(const TicketRequest& ticket) {
        root = insert(root, ticket);
    }

    bool compareTickets(const TicketRequest& t1, const TicketRequest& t2) {
        if (t1.flight_num == t2.flight_num) {
            if (t1.date == t2.date) {
                return t1.pass_name < t2.pass_name; 
            }
            return t1.date < t2.date; 
        }
        return t1.flight_num < t2.flight_num;
    }
    bool compareTicketsWithoutPassenger(const TicketRequest& a, const TicketRequest& b) {
        if (a.flight_num == b.flight_num) {
            return a.date < b.date; // ���������� ������ �� ����
        }
        return a.flight_num < b.flight_num; // ���������� �� ������ �����
    }

    void inOrderTraversal(NodeT* node) {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << "Destination: " << node->data.destination
                << ", Flight Number: " << node->data.flight_num
                << ", Passenger: " << node->data.pass_name
                << ", Departure Date: " << node->data.date << "\n";
            inOrderTraversal(node->right);
        }
    }
    void displayTickets() {
        if (root == nullptr) {
            std::cout << "������ ������." << std::endl;
        }
        else {
            inOrderTraversal(root);  // ������� ������ � ������� �����������
            std::cout << std::endl;
        }
        
    }


    void removeTicket(const string& flightNumber, const string& date, const string& passengerName) {
        if (root == nullptr) {
            cout << "������ ������!\n";
            return;
        }
        TicketRequest ticket("", flightNumber, passengerName, date);
        if (remove(root, ticket)) {
            std::cout << "Ticket removed successfully.\n";
        }
        else {
            std::cout << "Ticket not found.\n";
        }
    }

    // ����� ��� �������� ���� ������ �� ������ ����� � ���� ������
    void removeTicket(const string& flightNumber, const string& date) {
        while (removeall(root, TicketRequest("", flightNumber, "", date))) {
            std::cout << "Removed a matching ticket.\n";
        }
        std::cout << "All matching tickets removed.\n";
    }

    bool remove(NodeT*& node, const TicketRequest& fdata) {
        std::cout << "Checking node: " << node->data.flight_num
            << ", " << node->data.date
            << ", " << node->data.pass_name << "\n";
        if (compareTickets(fdata, node->data)) {
            return remove(node->left, fdata); // ���� � ����� ���������
        }
        else if (compareTickets(node->data,fdata)) {
            return remove(node->right, fdata); // ���� � ������ ���������
        }        
        else {
            // ���� ������
            deleteNode(node);
            return true; // �������� ��������
        }
    }
    
    bool removeall(NodeT*& node, const TicketRequest& fdata) {
        if (!node) return false;
        std::cout << "Checking node: " << node->data.flight_num
            << ", " << node->data.date
            << ", " << node->data.pass_name << "\n";
        if (compareTicketsWithoutPassenger(fdata, node->data)) {
            return removeall(node->left, fdata); // ���� � ����� ���������
        }
        else if (compareTicketsWithoutPassenger(node->data, fdata)) {
            return removeall(node->right, fdata); // ���� � ������ ���������
        }
        else {
            // ���� ������
            deleteNode(node);
            return true; // �������� ��������
        }
    }
    void deleteNode(NodeT*& node) {
        // ������ 1: ���� ��� �����
        if (node->left == nullptr && node->right == nullptr) {
            delete node; // ������� ����
            node = nullptr; // �������� ���������
        }
        // ������ 2: ���� � ����� ��������
        else if (!node->left) {
            NodeT* temp = node;
            node = node->right; // �������� �� ������� �������
            delete temp; // ����������� ������
        }
        else if (!node->right) {
            NodeT* temp = node;
            node = node->left; // �������� �� ������ �������
            delete temp; // ����������� ������
        }
        // ������ 3: ���� � ����� ������
        else {
            NodeT*& minNode = FindMin(node->right); // ������� ����������� ���������
            node->data = minNode->data; // �������� ������ ���������
            removeall(node->right, minNode->data); // ������� ��������� �� ������� ���������
        }
    }
    NodeT*& FindMin(NodeT*& node) {
        return (node->left == nullptr) ? node : FindMin(node->left);

    }
    int PrintOptiones(AEROFLOT* array) {
        cout << "������� 1 - �� �������, 2 - � ����" << endl;
        int select, flag = 0;
        cin >> select;
        switch (select)
        {
        case 1: displayTickets(array); break;
        case 2: flag = Save(array);
            if (flag != 0) return 1;
            break;
        default: return 2;
        }
        return 0;
    }
    bool ReadFile(const string file_name, AEROFLOT*& array)
    {
        ifstream in;
        in.open(file_name);
        if (!in.is_open())
        {
            cout << "�� ������� ������� ���� " + file_name << endl;
            return 0;
        }
        stringstream obj;
        string str;

        for (int i = 0; i < N; i++)
        {
            getline(in, str);
            obj << str + "\n";
        }
        in.close();

        for (int i = 0; i < N; i++)
        {
            string str;
            getline(obj, str);
            int index = str.find(' ');
            array[i].destination = str.substr(0, index);
            str = str.substr(index + 1);
            index = str.find(' ');
            array[i].num = stoi(str.substr(0, index));
            str = str.substr(index + 1);
            index = str.find(' ');
            array[i].type = str.substr(0, index);
            str = str.substr(index + 1);
        }
        return 1;
    }
    int Save(AEROFLOT* array)
    {
        string outputfile = "2.txt";
        ofstream out(outputfile); //������� ���� ��� ����������, ������� ����  ���� ��� ���
        if (!out.is_open())
        {
            cout << "�� ������� ������� ���� " + outputfile;
            return 1;
        }
        for (int i = 0; i < N; i++) {
            out << array[i].destination << " " << array[i].num << " " << array[i].type << endl;
        }
        out.close();
        return 0;
    }

};


int main()
{
    BinaryTree tree;

    tree.insert(TicketRequest("New York", "AA103", "Ivanov I.I.", "2024-10-15"));
    tree.insert(TicketRequest("Los Angeles", "AA101", "Petrov P.P.", "2024-10-16"));
    tree.insert(TicketRequest("Chicago", "AA103", "Sidorov S.S.", "2024-10-15")); // ��������
    tree.insert(TicketRequest("New York", "AA104", "Ivanov I.I.", "2024-10-15")); // ��������
    tree.insert(TicketRequest("New York", "AA108", "Ivanov I.I.", "2024-10-15"));
    tree.insert(TicketRequest("New York", "AA103", "Ivanov I.I.", "2024-10-15"));
    tree.insert(TicketRequest("New York", "AA103", "Ivanov I.I.", "2023-10-15"));

    std::cout << "All tickets:\n";
    tree.displayTickets();

    //tree.removeTicket("AA103", "2024-10-15", "Ivanov I.I.");
    tree.removeTicket("AA103", "2024-10-15");

    tree.displayTickets();
    return 0;
}

