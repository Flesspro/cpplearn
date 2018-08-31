#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
using namespace std;

class Date {
public:
  Date (const int& y, const int& m, const int& d) {
	  year = y;
	  month = m;
	  day = d;
  }
  Date () {
	  year = 0;
	  month = 0;
	  day = 0;
  }
  int GetYear() const{
	  return year;
  }
  int GetMonth() const {
	  return month;
  }
  int GetDay() const {
	  return day;
  }
  
  // Add friend to include reloaded operator in other classes
  friend  ostream& operator<<(ostream& stream, const Date& dt);
  
private:
  int year;
  int month;
  int day;
};


// Need to reload < to make map work with Date as key

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear()) {
		return true;
	} else if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) {
		return true;
	} else if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() &&
			lhs.GetDay() < rhs.GetDay()) {    // if replaced with "==", prevents map from working, but no error is thrown
		return true;
	} else return false;
}

class Database {
public:
  
  void AddEvent(const Date& date, const string& event){
	  db[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
	  
	  // Check if the date exists
	  if (db.count(date) == 0) {
		  return false;
	  }
	  
	  // Find the event
	  auto iter = db.at(date).find(event) ;
	  
	  if (iter != db.at(date).end() ) {
		  db.at(date).erase(iter);
		  return true;
	  } else {
		  // if event not found
		  return false ;
	  }
  }
  
  int  DeleteDate(const Date& date) {
	  int res = 0;
	  
	  if (db.count(date) != 0) {
		  res = db.at(date).size();
		  db.erase(date);
	  }
	  return res;
  }

  void Find(const Date& date) const {   
	  if (db.count(date) != 0) {
		  for (auto val : db.at(date)) {
			  cout << val << endl;
		  }
	  }
  }
  
  void Print() const {
	  for (auto const& dt_iter : db) {
		  for (auto const& event_iter : dt_iter.second) {
			  cout << dt_iter.first << " " << event_iter << endl;
		  }
	  }
  }
  
private:
  map<Date, set<string> > db;
};

void EnsureNextSymbolAndSkip(stringstream& stream, const string& s, const bool& state) {
	// state == false means checking inner characters; state == true means checking end of line 
	if ((!state && stream.peek() != '-') || (state &&  !stream.eof())) {
		throw runtime_error("Wrong date format: " + s);
	}
	stream.ignore(1);
}

Date ParseDate(const string& s){
	
	stringstream stream(s);
	
	int y, m, d;
	stream >> y;
	
	// Check agains 0$1-2
	EnsureNextSymbolAndSkip(stream, s, false);
	stream >> m;
	
	// Check agains 0-1#2
	EnsureNextSymbolAndSkip(stream, s, false);
	stream >> d;
	
	// Check against 0-1-2dfsfd
	EnsureNextSymbolAndSkip(stream, s, true);
	
	if (m < 1 || m > 12) {
		throw runtime_error("Month value is invalid: " + to_string(m));
	} else if (d < 1 || d > 31) {
		throw runtime_error("Day value is invalid: " + to_string(d));
	}
	
	//cout << y << "-" << m << "-" << d << endl;
	
	return Date(y, m, d);
	
}

ostream& operator<<(ostream& stream, const Date& dt) {
	stream << setfill ('0');
	stream << setw(4) << dt.GetYear() << '-'
			<< setw(2) << dt.GetMonth() << '-'
			<< setw(2) << dt.GetDay();
	return stream;
}

int main() {
  Database db;
  string command;
  
  while (getline(cin, command)) {
	// Ignore empty strings
	if (command == "")
	  continue;

	istringstream input(command);
	string opn, event, dtstring;
	Date dt;
	
	input >> opn;
	
	try {

		if (opn == "Add") {
			input >> dtstring >> event;
			dt = ParseDate(dtstring);
		
			db.AddEvent(dt, event);
		
		} else if (opn == "Del") {
			input >> dtstring >> event;
			dt = ParseDate(dtstring);
		
			// If this is a DeleteEvent command (event nonempty)
			if (event != "") {  
				if (db.DeleteEvent(dt, event)) {
					cout << "Deleted successfully" << endl;
				} else {
					cout << "Event not found" << endl;
				}
			} else {
				// if this is a DeleteDate command (event empty)
			
				cout << "Deleted " << db.DeleteDate(dt) << " events" << endl;
			}
		
		
		} else if (opn == "Find") {
			input >> dtstring;
			dt = ParseDate(dtstring);
		  
			db.Find(dt);
		
		} else if (opn == "Print") {
		
			db.Print();
		
		} else {
			// If command is not correct
			cout << "Unknown command: " << opn << endl;
		}

	} catch (exception& ex) {
		cout << ex.what() << endl;
	}
  }
  
  return 0;
}
