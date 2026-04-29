# ⚖️ Case Management System — C++ Data Structures

A console-based **Case Management System** built in C++ from scratch using custom data structures. Each case is stored in a **AVL Tree**, and every case node maintains its own linked lists for **Evidence**, **Custody**, and **Officers** — forming a rich, interconnected data model without any STL containers.

---

## 🗂️ Data Structure Design

```
CaseTree (AVL)
└── CaseNode
    ├── CaseInfo         (case details: ID, title, status, etc.)
    ├── EvidenceList     (linked list of evidence items)
    ├── CustodyList      (linked list of custody records)
    └── OfficerList      (linked list of assigned officers)
```

- **CaseTree** — AVL for efficient case insertion, search, and deletion by case ID
- **EvidenceList** — singly linked list storing evidence attached to a case
- **CustodyList** — doubly linked list tracking chain of custody per case
- **OfficerList** — circular linked list of officers assigned to a case

---

## 📁 File Structure

| File | Description |
|---|---|
| `CaseInfo.cpp` | Case data model (ID, title, status, date, etc.) |
| `CaseNode.cpp` | BST node containing CaseInfo + all three linked lists |
| `CaseTree.cpp` | Binary Search Tree — insert, search, delete, traverse |
| `CaseTrackingSystem.cpp` | Main driver — menu, user interaction, system flow |
| `EvidenceNodeClass.cpp` | Node definition for evidence linked list |
| `EvidenceListClass.cpp` | Linked list operations for evidence |
| `CustodyNodeClass.cpp` | Node definition for custody linked list |
| `CustodyListClass.cpp` | Linked list operations for custody records |
| `OfficerNodeClass.cpp` | Node definition for officer linked list |
| `OfficerListClass.cpp` | Linked list operations for assigned officers |

---

## ⚙️ How to Compile & Run

```bash
g++ CaseInfo.cpp CaseNode.cpp CaseTree.cpp CaseTrackingSystem.cpp \
    EvidenceNodeClass.cpp EvidenceListClass.cpp \
    CustodyNodeClass.cpp CustodyListClass.cpp \
    OfficerNodeClass.cpp OfficerListClass.cpp \
    -o CaseManagementSystem

./CaseManagementSystem
```

---

## 🛠️ Tech Stack

| | |
|---|---|
| Language | C++ |
| Data Structures | AVL, Singly Linked List, Doubly Linked List, Circularly Linked List |
| Interface | Console / CLI |
| STL Used | None — all custom implementations |

---

## 📄 License

Academic project — free to use for learning purposes.

---

<p align="center">Built with 🖥️ C++ · Raw Data Structures · No STL</p>
