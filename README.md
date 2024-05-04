
#  *----------------  Wheaton College, MA - Spring 2024   ---------------* <br><br><br>

## COMP 318 Algorithms - Project 3 
### Description - ***Greedy & Dynamic Programming***
This project introduces an implementation of a Balanced Binary Search Tree (BST), specifically an AVL tree, which 
self-balances to maintain optimal search, insert, and delete operations times.The program offers multiple options to 
manage a balanced BST effectively, leveraging various algorithms and data structures, including tree nodes, rotation mechanisms, 
and balanceOurTree factor calculations.

#### **Highlights of the project:**

* **Data Insertion:** Safely inserts data into the tree, guaranteeing the maintenance of BST properties.
* **Tree Traversals:** Implements and demonstrates in-order, pre-order, post-order, and level-order traversals of the tree.
* **Tree Visualization:** Displays up to four levels of the tree, providing a clear visual representation of its structure.
* **Balance Factor Calculation:** Calculates and displays the balanceOurTree factors, crucial for understanding the AVL tree's balanceOurTree.
* **Single Rotations:** Executes single right and left rotations to maintain AVL tree balanceOurTree after insertions and deletions.
* **Double Rotations:** Performs left-right and right-left rotations to balanceOurTree more complex imbalances in the tree.

Developed by Sam Hammami '25

****************************
**Inheritance diagram bla bla:**
****************************
 ```mermaid
graph TD;
    binaryTreeClas<-->binarySearchTreeClass;
    binarySearchTreeClass<-->balancedBinarySearchTreeClass;
    balancedBinarySearchTreeClass-->Main.cpp;
```
##### This project contains multiple files that divide the workload.
- main.cpp: <br>
    This file is used to test the AVL Trees implementation. It creates a tree, inserts nodes, displays the tree, and deletes nodes. 
    It also displays the tree after deletion.

- changeMaker.cpp:<br>
    This file is used to create the AVL Trees Object Data Structure which holds the nodes of the tree and the methods to manipulate the tree.

- changeMaker.h:<br>
  This is the header file for the AVLtrees.cpp file. It contains the three classes hierarchy (binaryTreeClass, binarySearchTreeClass, balancedBinarySearchTreeClass) and the methods' prototypes. <br>

****************************

## Getting Started

#### This program uses the following libraries:

- #include <iostream> // For input-output
- #include <array>    // For Greedy Programming
- #include <vector>   // For Dynamic Programming
- #include <cmath>    // For INT_MAX
- #include <string>   // For string manipulation
- #include <iomanip>  // For setw

#### CMake Minimum version
- cmake_minimum_required(VERSION 3.27)

### Compiler version
- Clang C++ compiler

### Installing /compiling

#### On CLion

After downloading the code, please create a new project on CLion and select the folder containing the program as the project folder.
It will ask you to either use the files existing inside the folder or create a blank design, please select to use the files inside the folder.
The CMakeList.txt file and cmake-build-debug folder should include all the necessary files needed to run this program on CLion.

### Executing program

#### On CLion
Click the run button - or - Shift + F10

<br><br>
<br><br>
<br><br>
<br><br>

#### Run the code - It should be like: 

```


Sample 1
***     Welcome to the IR$ of Banana Republic!     ***

Please enter your name below!
My Name is Poor Patrick

What is your tax $$$ due?
My Tax Amount Due = $96003

---------------------------------------------------------------
Plan 1: The Greedy Approach
Tax Due: $96003
                Bills         Num                   Subtotal
                $95000   x    1     = $95000        $95000
                $32001   x    0     = $0            $95000
                $5001    x    0     = $0            $95000
                $701     x    1     = $701          $95701
                $101     x    2     = $202          $95903
                $1       x    100   = $100          $96003

Total number of bills needed: 1 + 0 + 0 + 1 + 2 + 100 = 104
*-----------------------------*****---------------------------*
Plan 2: The Dynamic Programming Approach
Tax Due: $96003
                Bills         Num                   Subtotal
                $95000   x    0     = $0            $0
                $32001   x    3     = $96003        $96003
                $5001    x    0     = $0            $96003
                $701     x    0     = $0            $96003
                $101     x    0     = $0            $96003
                $1       x    0     = $0            $96003

Total number of bills needed: 0 + 3 + 0 + 0 + 0 + 0 = 3
---------------------------------------------------------------
Which payment plan do you want to choose (1 or 2)?
Plan:2

---------------------------------------------------------------
Dear  Poor Patrick,

Thank you for paying your tax ON TIME, you have chosen Plan 2!
Remember that IR$ of Banana Republic is always here for you.

Best Regards,
IR$ Support Team
---------------------------------------------------------------

Sample 2



Sample 3




We could see that always dp < greedy


Which result that dp is always more efficient but sometimes greedy is the same as dp

we could see the difference between the two algorithms in larger numbers where dp is more efficient than greedy




Time complexity


Space complexity




Time efficiency
Space efficiency
Which approach is better? Why? Is it always the case?

```

```
.                        ***     Welcome to The AVL Trees World     ***                    .


--------------------------------------------------------------------------------------------------




```
****************************
## Authors 
List of authors/contributors’ names and contact info:

* Sam Hammami '25 - hammami_houssem@wheatoncollege.edu
****************************
## Version History 

* Starter Code Uploaded - April 27, 2024

* CLion Set up - April 27, 2024

* Adjusted AVLTrees.h - April 05, 2024

* Completed 1st Class (BT) - April 06, 2024

* Some work on Main.cpp - April 06, 2024

* Planning Binary Search Tree Class - April 06, 2024

* Developed 2nd Class (BST) - April 07, 2024

* Started Implementing 3rd Class (B_BST) - April 07, 2024

* Checking Rotations (Single/Double) - April 09, 2024

* Discussing the project with Prof. Tony - May 02, 2024

* Solved nodeType Typo issue - April 09, 2024

* Completed the 2nd Class (BST) - April 10, 2024

* Discussed my AVLtrees.cpp/.h with Peer Tutor.h - April 10, 2024

* Solved some issues & More work on Main.cpp - April 10, 2024

* Completed the 3rd Class (B_BST) - April 11, 2024

* Testing Main.cpp (Specific Cases, Display, Delete) - April 11, 2024

* Commenting the code (Sam style) - April 12, 2024

* Final Testing - April 12, 2024

* Checking-In with Professor **Tony** - May 04, 2024

* Uploaded_Final Version - May 04, 2024
****************************

## License
This project is licensed under the [MIT] License - see the LICENSE file for details
****************************
## Acknowledgments

- We acknowledge all the programming input Prof. **Martin Gagné** put into this program.
- We acknowledge all the programming input from Prof. **Tony Tong** put into this program.
- We also acknowledge **Sam Hammami** for his hard work and dedication to this project.

