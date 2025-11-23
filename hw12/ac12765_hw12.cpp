/*
Homework 12: Checkbook Balancing
    CH12 #7: Write a checkbook balancing program. The program will read in, from the
console, the following for all checks that were not cashed as of the last time you balanced your
checkbook:

  - The number of each check (int)
  - The amount of the check (double)
  - Whether or not it has been cashed (1 or 0, boolean in the array)

    Use an array with the class as the type. The class should be a class for a check. There
should be three member variables to record the check number, the check amount, and whether
or not the check was cashed. The class for a check will have a member variable of type Money
(as defined on page 662 in the book; Display 11.9) to record the check amount. So, you will
have a class used within a class. The class for a check should have accessor and mutator
functions as well as constructors and functions for both input and output of a check. In addition
to the checks, the program also reads all the deposits (from the console; cin), the old and the
new account balance (read this in from the user at the console; cin). You may want another
array to hold the deposits. The new account balance should be the old balance plus all deposits,
minus all checks that have been cashed.

The program outputs the total of the checks cashed, the total of the deposits, what the new
balance should be, and how much this figure differs from what the bank says the new balance
is. It also outputs two lists of checks: the checks cashed since the last time you balanced your
checkbook and the checks still not cashed. [ edit: if you can, Display both lists of checks in
sorted order from lowest to highest check number.]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Money
{
public:
    // overload operators
    friend Money operator +(const Money &amount1, const Money &amount2) { return Money(0, amount1.all_cents + amount2.all_cents); }
    // Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money &amount1, const Money &amount2) { return Money(0, amount1.all_cents - amount2.all_cents); }
    // Returns amount1 minus amount2.
    friend Money operator -(const Money &amount) { return Money(0, -amount.all_cents); }
    // Returns the negative of the value of amount.
    friend bool operator ==(const Money &amount1, const Money &amount2) { return amount1.all_cents == amount2.all_cents; }
    // Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money &amount1, const Money &amount2) { return amount1.all_cents < amount2.all_cents; }
    // Returns true if amount1 is less than amount2; false otherwise.
    friend bool operator >(const Money &amount1, const Money &amount2) { return amount1.all_cents > amount2.all_cents; }
    // Returns true if amount1 is greater than amount2; false otherwise.

    Money& operator +=(const Money& other);
    Money& operator -=(const Money& other);

// constructors
Money(long dollars, int cents) : all_cents(dollars * 100 + cents) {}
// Initializes the object so its value represents an amount with
// the dollars and cents given by the arguments. If the amount
// is negative, then both dollars and cents should be negative.
Money(long dollars) : all_cents(dollars * 100) {}
// Initializes the object so its value represents $dollars.00.
Money() : all_cents(0) {}
// Initializes the object so its value represents $0.00.

// accessors & mutators
double get_value() const { return all_cents * 0.01; }
// Returns the amount of money recorded in the data portion of the calling
// object.

// input & output
friend istream &operator >>(istream &ins, Money &amount);
// Overloads the >> operator so it can be used to input values of type
// Money. Notation for inputting negative amounts is as in - $100.00.
// Precondition: If ins is a file input stream, then ins has already been
// connected to a file.
friend ostream &operator <<(ostream &outs, const Money &amount);
// Overloads the << operator so it can be used to output values of type
// Money. Precedes each output value of type money with a dollar sign.
// Precondition: If outs is a file output stream, then outs has already been
// connected to a file.
private:
    long all_cents;
};

class Check
{
    int check_number;
    Money check_amount;
    bool is_cashed;
public:
    // constructors
    Check() : check_number(0), check_amount(), is_cashed(false) {}
    Check(int number, Money amount, bool is_cashed) : check_number(number), check_amount(amount), is_cashed(is_cashed) {}

    // input & output
    void input();
    void output() const;
    
    // accessors and mutators
    int get_check_number() const { return check_number; }
    Money get_check_amount() const { return check_amount; }
    bool get_is_cashed() const { return is_cashed; }

    void set_check_number(int new_check_number) { check_number = new_check_number; }
    void set_check_amount(Money new_check_amount) { check_amount = new_check_amount; }
    void set_is_cashed(bool new_is_cashed) { is_cashed = new_is_cashed; }
};

void sort_checks(vector<Check>& checks);

int main() {
    cout << "Checkbook Balancing Program.\n";
    cout << "-------------------------------------------------------------------------------------------------\n";
    vector<Check> checks;
    cout << "Please enter how many checks you have: ";
    int num_of_checks;
    cin >> num_of_checks;

    for (int i = 0; i < num_of_checks; i++) {
        cout << "\nCheck #" << i + 1 << " details:" << endl;
        Check check;
        check.input();
        checks.push_back(check);
    }

    vector<Money> deposits;
    cout << "\nPlease enter deposits you have: ";
    int num_of_deposits;
    cin >> num_of_deposits;

    cout << "Please enter one deposit per line in the following format $##.##: \n";

    for (int i = 0; i < num_of_deposits; i++) {
        cout << "\nDeposit #" << i + 1 << " details:" << endl;
        Money deposit;
        cin >> deposit;
        deposits.push_back(deposit);
    }


    
    Money old_balance;
    cout << "\nPlease enter your prior balance amount (format $##.##): ";
    cin >> old_balance;

    vector<Check> cashed_checks;
    vector<Check> uncashed_checks;

    for (int i = 0; i < checks.size(); i++) {
        if (checks[i].get_is_cashed()) {
            cashed_checks.push_back(checks[i]);
        } else {
            uncashed_checks.push_back(checks[i]);
        }
    }

    Money total_cashed_checks;
    for (int i = 0; i < cashed_checks.size(); i++) {
        total_cashed_checks += cashed_checks[i].get_check_amount();
    }

    Money total_uncashed_checks;
    for (int i = 0; i < uncashed_checks.size(); i++) {
        total_uncashed_checks += uncashed_checks[i].get_check_amount();
    }

    Money total_deposits;
    for (int i = 0; i < deposits.size(); i++) {
        total_deposits += deposits[i];
    }

    Money new_balance = old_balance + total_deposits;
    Money calculated_new_balance = old_balance + total_deposits - total_cashed_checks;
    Money checkbook_balance = old_balance + total_deposits - total_cashed_checks - total_uncashed_checks;
    Money difference = calculated_new_balance - checkbook_balance;

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    cout << "The cashed checks are: \n";
    if (cashed_checks.size() > 0) {
        sort_checks(cashed_checks);
        for (int i = 0; i < cashed_checks.size(); i++) {
            cashed_checks[i].output();
        }
    }
    else if (cashed_checks.size() == 0) {
        cout << "None\n";
    }
    cout << "The sum of the cashed checks is: " << total_cashed_checks << endl;

    cout << "\nThe uncashed checks are: \n";
    if (uncashed_checks.size() > 0) {
        sort_checks(uncashed_checks);
        for (int i = 0; i < uncashed_checks.size(); i++) {
            uncashed_checks[i].output();
        }
    } 
    else if (uncashed_checks.size() == 0) {
        cout << "None\n";
    }

    cout << "The sum of the un-cashed checks is: " << total_uncashed_checks << endl;
    cout << "\n-------------------------------------------------------------------------------------------------\n";

    cout << "The sum of your deposits is: " << total_deposits << endl;
    cout << "Your new balance is: " << new_balance << endl;
    cout << "\n-------------------------------------------------------------------------------------------------\n";

    cout << "The balance according to the bank which only includes deposits and cashed checks is: " << calculated_new_balance << endl;
    cout << "Your checkbook balance which also includes uncashed checks is: " << checkbook_balance << endl;
    cout << "The difference between checkbook balance of " << checkbook_balance << " and bank balance of " << calculated_new_balance << " is: " << difference << endl;

    return 0;
}

Money& Money::operator +=(const Money& other) {
    this->all_cents += other.all_cents;
    return *this;
}

Money& Money::operator -=(const Money& other) {
    this->all_cents -= other.all_cents;
    return *this;
}

istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point;
    long dollars;
    int cents;
    bool is_negative = false;

    ins >> one_char;

    if (one_char == '-') {
        is_negative = true;
        ins >> one_char;
    }

    ins >> dollars >> decimal_point >> cents;

    if (one_char != '$' || decimal_point != '.' || dollars < 0 || cents < 0 || cents > 100) {
        cout << "Error: Invalid input format for Money. Please use the format $##.##.\n";
        exit(1);
    }

    amount.all_cents = dollars * 100 + cents;
    if (is_negative) {
        amount.all_cents = -amount.all_cents;
    }
     
    return ins;
}

ostream& operator <<(ostream& outs, const Money& amount) {
    int pos_all_cents, cents;
    long dollars;
    
    pos_all_cents = abs(amount.all_cents);
    dollars = pos_all_cents / 100;
    cents = pos_all_cents % 100;

    if ((amount.all_cents) < 0) {
        outs << '-';
    }

    outs << '$' << dollars << '.';

    if (cents < 10) {
        outs << '0';
    }

    outs << cents;

    return outs;
}

void Check::input() {
    cout << "Please enter the check number: ";
    cin >> check_number;
    cout << "Please enter the amount on check (in the form $##.##): ";
    cin >> check_amount;
    cout << "Please enter whether or not the check has been cashed by typing Y(Yes) or N(No): ";
    char temp;
    cin >> temp;
    if (temp == 'Y' || temp == 'y') {
        is_cashed = true;
    } else if (temp == 'N' || temp == 'n') {
        is_cashed = false;
    } else {
        cout << "Error: Invalid input for check status. Please enter Y or N.\n";
        exit(1);
    }
}

void Check::output() const {
    cout << "Check number: " << check_number << " with amount: " << check_amount << endl;
}

void sort_checks(vector<Check>& checks) {
    for (int i = 0; i < checks.size() - 1; i++) {
        for (int j = 0; j < checks.size() - 1 - i; j++) {
            if (checks[j].get_check_amount() > checks [j + 1].get_check_amount()) {
                Check temp = checks[j];
                checks[j] = checks[j + 1];
                checks[j + 1] = temp;
            }
        }
    }
}