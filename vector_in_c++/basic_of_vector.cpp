// vector are dynamic array
// dynamic array -> resize when insert or delete elements
// array are static
// vector also have contiuous memory location

// declaration 
// #include<vector> 
// vector<data type> vector-name;
// vector<data type>vector-name(size); here size is optional

// for length of vector-> vector-name.size();
// for resize vector-name(new size);

//capacity  
// vector-name.capacity();
// always capcity >= size

// if we increase vector size by one by one element then capacity 
// increse in 2 powers or depend upon complier
// else depend on complier

// for add element at end of position
//  vector-name.push_back(element);

// for add element at particular position
//we need find position of first element by-> vector-name.begin();
// vector-name.insert(vector-name.begin(),element)

// ex. v.insert(v.begin()+2,5) means-> insert 5 at 3rd position 

// for delete last element
// vector-name.pop_back()

// for particular element
// vector-name.erase(vetor-name.begin()+i) or (vector-name.end()-i)