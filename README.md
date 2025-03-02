# Data Structures and Algorithms Portfolio

## Project Submissions
This portfolio highlights two projects that demonstrate my proficiency in data structures and algorithms:

- **Project One**: Analyzing the runtime and memory usage of different data structures.
- **Project Two**: Developing a program that sorts and displays Computer Science courses in alphanumeric order.

---

## Project One: Runtime and Memory Analysis

### Objective
This project focused on evaluating the efficiency of three data structures—Vector, Hash Table, and Binary Search Tree (BST)—to determine the best option for storing and retrieving course information efficiently.

### Approach & Findings
- **Vector**: Easy to implement but inefficient for searching.
- **Hash Table**: Offers fast lookups but doesn’t maintain order.
- **BST**: Balances ordered storage with efficient search operations.

### Runtime Complexity Comparison
| Data Structure  | Insertion | Sorting | Searching |
|----------------|-----------|---------|-----------|
| **Vector**    | O(1) (avg) | O(n log n) | O(n) |
| **Hash Table** | O(1) (avg) | N/A | O(1) (avg) |
| **BST**       | O(log n) (avg) | N/A | O(log n) (avg) |

### Final Choice
The **BST** was selected as the optimal structure since it ensures both efficient retrieval and ordered output.

---

## Project Two: Course Sorting and Display

### Objective
The goal was to develop a program that loads course data from a file, organizes it efficiently, sorts it, and displays courses in alphanumeric order.

### Implementation
- **Used a hash table (map)** for fast data retrieval.
- **Implemented bubble sort** to arrange courses in order.
- **Enabled user interaction** for searching course details.

### Challenges & Solutions
- **File Handling Issues**: Ensured the file existed before processing.
- **Sorting Efficiency**: Started with bubble sort but identified quicker alternatives like quicksort or mergesort.
- **Search Case Sensitivity**: Standardized input to uppercase for consistency.

---

## Reflection & Key Takeaways

### Lessons Learned
- Choosing the right data structure is crucial for efficiency.
- Encountering roadblocks strengthened my problem-solving and debugging skills.
- Writing clean, maintainable code improves long-term software usability.

### Growth in Programming Skills
This project enhanced my ability to:
- Analyze and compare runtime complexities.
- Implement sorting and searching algorithms effectively.
- Write structured, optimized, and scalable code.

This portfolio showcases both my **theoretical understanding** of data structures and **practical implementation skills**, reinforcing my ability to develop efficient software solutions.

