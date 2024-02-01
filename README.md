# Linked List Implementation

This C++ program implements a linked list with the ability to shift itself into a header linked list. It supports common operations such as insertion, deletion, and searching.

**Author:** Saim Ahmed Emon

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Functions](#functions)
- [How to Contribute](#how-to-contribute)
- [License](#license)

## Description

This C++ program demonstrates the implementation of a linked list. It provides a set of functions to manipulate the linked list, including adding elements at the beginning or end, inserting at a specific position, and deleting elements.

## Features

- Creation of a linked list.
- Insertion of elements at the beginning, end, or specific positions.
- Deletion of elements from the beginning, end, or specific positions.
- Searching for an element in the linked list.
- Header list functionality.

## Usage

To use this linked list implementation, follow these steps:

1. **Clone the repository:**

    ```bash
    git clone https://github.com/yourusername/linked-list.git
    cd linked-list
    ```

2. **Compile the code:**

    ```bash
    g++ linked_list.cpp -o linked_list
    ```

3. **Run the executable:**

    ```bash
    ./linked_list
    ```

4. Explore the linked list functionalities by adding, deleting, and searching for elements.

## Functions

- **`createNode(int value)`**
  - Creates a new node with the given value.

- **`createList()`**
  - Creates a new linked list.

- **`display(list head)`**
  - Displays the elements of the linked list.

- **`addLast(list head, int value)`**
  - Adds an element to the end of the linked list.

- **`addFirst(list head, int value)`**
  - Adds an element to the beginning of the linked list.

- **`add(list head, int value, int index)`**
  - Adds an element at a specific position in the linked list.

- **`deleteFirst(list head)`**
  - Deletes the first element from the linked list.

- **`deleteNode(list head, int index)`**
  - Deletes the element at a specific position in the linked list.

- **`deleteLast(list head)`**
  - Deletes the last element from the linked list.

- **`searchNode(list head, int item)`**
  - Searches for a specific element in the linked list and returns its index.

## How to Contribute

If you want to contribute to this project, you can:

- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make changes and submit a pull request.

## License

This project is licensed under the MIT License.
