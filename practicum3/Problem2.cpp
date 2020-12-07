Create a class Book with the data members listed below.  
title,  which is a string (initialize to empty string)
sales, which is a floating point value (as a double, initialize to 0.0)
Include the following member functions:
Include a default constructor, 
a constructor with parameters for each data member (in the order given above), 
getters and setter methods for each data member named in camel-case.  For example, if a class had a data member named myData, the class would require methods named in camel case: getMyData and setMyData. 
int sold(double unit) This function should calculate and return the total number of units sold, based on sales divided by unit, the input parameter argument for cost per unit.
You only need to write the class definition and any code that is required for that class (i.e., header and implementation).
NOTE:  you must not use the implicit "private" for class data types and methods. Include public or private explicitly.


class Book {
    private:
    string title;
    double sales;
    
    public:
    Book();
    Book(string title_, double sales_);
    void setTitle(string title_);
    string getTitle();
    void setSales(double sales_);
    double getSales();
    int sold(double unit);
};

Book:: Book() {
    title = "";
    sales = 0.0;
}

Book:: Book(string title_, double sales_) {
    title = title_;
    sales = sales_;
}

void Book:: setTitle(string title_){
    title = title_;
}

string Book:: getTitle(){
    return title;
}

void Book:: setSales(double sales_){
    sales = sales_;
}
    
double Book:: getSales(){
    return sales;
}

int Book:: sold(double unit){
    double returnVal;
    returnVal = sales/unit;
    return returnVal;
}

