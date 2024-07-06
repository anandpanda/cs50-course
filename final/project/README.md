# Employee Management System
#### Video Demo: https://www.youtube.com/watch?v=o1QDDHEjbNA
#### Description:
This employee management system in C provides essential functionalities for organizing and maintaining employee records efficiently. Here's a breakdown of its features:

Adds a new employee record to the database stored in a file.

Deletes a specified employee record from the database.

Allows for modifications to an existing employee record, updating information such as name, contact details, etc.

Displays all employee records currently stored in the system.

Enables searching for a particular employee record based on specified employee ID.

Utility function to print a specified character a given number of times, used for formatting purposes.

Displays basic information about the employee list, such as total number of employees and other summary data.

Provides contact details of employees, facilitating quick access to phone numbers, email addresses, etc.

Lists all male employees in the database.

Lists all female employees in the database.

Lists employees belonging to the main branch or headquarters of the organization.

Lists employees from satellite branches or offices other than the main branch.

## Purpose and Benefits:
This system is designed to streamline HR operations by centralizing employee information and providing efficient ways to add, modify, delete, and search employee records. It enhances organizational efficiency by ensuring quick access to employee data and facilitating informed decision-making regarding workforce management.

## Implementation:
The system uses file handling in C to store and retrieve employee records, ensuring data persistence across sessions. Functions are optimized for performance and ease of use, offering a user-friendly interface for HR personnel to manage employee information effectively.

## Future Enhancements:
Future updates may include additional features such as employee performance tracking, attendance management, and integration with payroll systems, further enhancing the system's utility in comprehensive HR management.


## Funtions and working Explained:

### Add Employee Function
The "Add Employee" function allows users to input new employee information and append it to the existing employee database stored in a file. This function provides a structured approach to gathering and storing essential employee details, facilitating seamless integration of new personnel into the Employee Management System.

Upon invocation, the function prompts the user to enter various details for the new employee, including:

- ID: Unique identification number assigned to the employee.
- Name: Full name of the employee, entered as a string.
- Designation: Job title or position held by the employee.
- Gender: Gender identity of the employee.
- Branch: Branch location or designation within the organization.
- Salary: Numeric value representing the employee's compensation.
- Present Address: Current residence or location of the employee.
- Permanent Address: Long-term residence or domicile of the employee.
- Phone: Contact number of the employee.
- Email: Email address of the employee.

Each input is validated and stored in a structured format defined by the Employee structure. The function ensures data integrity and completeness by handling input errors and utilizing file operations (fwrite) to append the new employee record to the existing file (employeeInfo.txt).

### Delete Function
The delete function allows the user to remove an employee record from the system based on the unique ID of the employee. When invoked, it prompts the user to enter the ID of the employee they wish to delete. The function then scans through the employee records stored in a file. It uses file operations to read each record, compare the ID with the one entered by the user, and if found, excludes that record from being copied to a temporary file. After processing all records, the original file is replaced with the temporary file, effectively deleting the specified employee record. This function ensures data integrity and provides a straightforward way to manage employee records by allowing selective deletion.

### Modify Function
The modify function enables users to update specific details of an employee record stored in the system. It begins by prompting the user to enter the ID of the employee whose details they wish to modify. Once the ID is provided, the function scans through the employee records stored in a file. Upon finding a record matching the entered ID, it allows the user to update various fields such as name, designation, salary, etc. User input is read and applied to the respective fields of the employee structure. The function then writes the updated record back to the file, ensuring that changes are persisted and reflected in the system. This functionality provides flexibility in managing employee information by facilitating easy updates without the need for re-entering entire records.

### Display List Function
The display list function retrieves and presents a comprehensive list of all employee records currently stored in the system. When invoked, it reads through the employee file and sequentially displays each record along with its associated details. These details typically include employee ID, name, designation, salary, joining date, gender, branch, addresses, phone number, and email. The function ensures that information is presented in a structured format, facilitating easy viewing and reference. This feature is essential for administrators and users to quickly review and verify employee information, aiding in efficient management and decision-making processes.

### Search Record Function
The search record function allows users to locate specific employee details based on their unique ID. Upon invocation, the function prompts the user to enter the ID of the employee they wish to find. It then scans through the employee records stored in the file, comparing each record's ID with the user-provided ID. If a match is found, it displays all pertinent details of the employee, including name, designation, salary, addresses, phone number, and email. This function facilitates quick retrieval of employee information, aiding in tasks such as verification, reference, or data analysis. It ensures efficient access to precise details without the need to browse through entire lists manually.

### Display Basic Information Function
The display basic information function provides a summarized view of essential employee details. It reads through the employee file and presents a condensed list of information that typically includes employee ID, name, designation, gender, branch, phone number, and email. This function offers a streamlined overview suitable for quick reference or general inquiries. By focusing on core details, it enhances usability for users needing essential employee information promptly. This feature is particularly useful in scenarios where a comprehensive list is unnecessary, ensuring efficiency in accessing key data points.

### Display Basic Contact Information Function
The display basic contact information function specifically focuses on presenting essential contact details of employees. It retrieves and displays critical information such as employee ID, name, designation, phone number, and email from the employee records stored in the system. This function caters to situations where immediate access to contact information is vital, facilitating communication or contact management tasks effectively. It ensures clarity and accessibility of key contact details, supporting seamless interaction and communication within the organization or with external parties.

### List of Male Employees Function
The list of male employees function filters and displays records of all male employees stored in the system. It reads through the employee file, identifies records where the gender field indicates male, and subsequently presents details such as employee ID, name, designation, and phone number. This function aids in demographic analysis, gender-specific reporting, or targeted communication efforts within the organization. By providing a segregated list based on gender, it supports diverse operational needs and enhances data-driven decision-making processes related to workforce management.

### List of Female Employees Function
Similar to the list of male employees function, the list of female employees function filters and displays records of all female employees stored in the system. It identifies records where the gender field indicates female and presents relevant details such as employee ID, name, designation, and phone number. This function facilitates gender-specific reporting, diversity analysis, or targeted communication initiatives within the organization. By offering a segregated list based on gender, it supports inclusive practices and enables tailored approaches to workforce management and engagement.

### List of Employees (Except from Delhi) Function
The function "List of Employees (Except from Delhi)" filters out employees whose permanent address includes "Delhi". It reads through the employee file, checks each record's permanent address field, and excludes those containing "Delhi" in any case (upper or lower). For qualifying records, it displays pertinent details such as employee ID, name, designation, phone number, and email. This function supports geographic analysis or operational decisions that require excluding employees based on specific location criteria. It enhances data accuracy and facilitates targeted strategies or reports focusing on employees outside the Delhi region.

### List of Employees from Main Branch Function
The "List of Employees from Main Branch" function identifies and displays records of employees associated with the main branch. It examines each employee record's branch designation (or permanent address, if indicated as "main") and retrieves details such as employee ID, name, designation, phone number, and email for qualifying records. This function supports branch-specific reporting, workforce segmentation, or operational planning related to the main branch's staff. By providing a dedicated list, it enables focused management and facilitates tailored communication or decision-making concerning main branch employees.

### List of Employees from Other Branches Function
Contrasting with the previous function, the "List of Employees from Other Branches" function retrieves records of employees not associated with the main branch. It scans through employee records, excludes those affiliated with the main branch based on their branch designation or permanent address, and presents details such as employee ID, name, designation, phone number, and email for each qualifying record. This function supports operational insights into employees outside the main branch, aiding in decentralized workforce management, geographical analysis, or targeted engagement strategies. It ensures comprehensive visibility and facilitates strategic decision-making across multiple branches or locations.
