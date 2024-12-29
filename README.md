# 📝 Note-Taking Application in C

Welcome to the **Note-Taking Application** built in C! This application allows you to **create**, **view**, **edit**, and **delete** your notes, making it a great tool to store important thoughts and reminders. The notes are stored in a file, and each note contains a **title** and **content**. This application helps you stay organized and keep track of your ideas. 🌟

---

## 💻 Features

1. **Add a Note** ➕
    - Easily add a new note with a title and content.
    - The content can be written over multiple lines, and typing `` ` `` on a new line finishes the note. ✍️

2. **View All Notes** 👀
    - View all the saved notes with their title and content. 📜
    - Each note is displayed with its unique ID. 🆔

3. **Edit a Note** ✏️
    - Edit an existing note by providing the note's ID.
    - Update the title and content of the note. 📝

4. **Delete a Note** ❌
    - Delete a note by specifying its ID. 💀
    - Deleted notes are permanently removed from the list! 🔥

5. **File-Based Storage** 📂
    - Notes are saved to and loaded from a file (`notes.txt`), ensuring **data persistence**. 💾

---

## ⚙️ How to Use

### 1. 🏁 Setup
   - Clone this repository using:
     ```bash
     git clone https://github.com/yourusername/notetaking-app.git
     ```

   - Navigate to the project directory:
     ```bash
     cd notetaking-app
     ```

### 2. 🔨 Compile the Program
   - Use `gcc` to compile the C program:
     ```bash
     gcc -o notetaking_app notetaking_app.c
     ```

### 3. 🚀 Run the Program
   - Start the program with:
     ```bash
     ./notetaking_app
     ```

   - You will be prompted with a menu to select the action you want to perform. 🎮

---

## 📋 Menu Options

The program presents a simple text-based menu with the following options:

1. **Add Note** ➕
    - You will be asked to enter the title and content for the new note.
    - Content ends when you type `` ` `` on a new line.

2. **View All Notes** 👀
    - Displays a list of all saved notes with their IDs, titles, and content.

3. **Edit Note** ✏️
    - To edit a note, you need to enter the **ID** of the note you want to modify.
    - You can update both the title and content of the note.

4. **Delete Note** ❌
    - Enter the **ID** of the note you wish to delete.
    - Once deleted, the note cannot be recovered! 🗑️

5. **Exit** 🚪
    - Exit the application and save all changes. 📴

---

## 🧑‍💻 Code Breakdown

### 1. **Structures** 🏗️
   - The `Note` structure holds the following fields:
     - `id`: Unique identifier for each note. 🎫
     - `title`: The title of the note. 🏷️
     - `content`: The content of the note. 📄

### 2. **Functions** 🛠️

- **addNote()** ➕
    - Adds a new note to the file by prompting the user for a title and content.
    - The note is saved to the file `notes.txt`. 💾

- **viewNotes()** 👀
    - Reads and displays all saved notes from the `notes.txt` file.

- **editNote()** ✏️
    - Allows the user to edit a specific note by ID, updating the title and content.

- **deleteNote()** ❌
    - Deletes a note by ID by creating a temporary file and removing the target note.

- **getNewNoteId()** 🔢
    - Generates a new unique ID for each note by scanning the existing notes.

- **saveNote()** 💾
    - Saves a note to the file `notes.txt`.

---


--- Note-Taking Application ---
1. Add Note
2. View All Notes
3. Edit Note
4. Delete Note
5. Exit
Enter your choice: 1

Enter title of the note: Meeting Notes 🗣️
Enter content of the note (type ` on a new line to finish):
Discuss project timeline. 🕒
Make sure to follow up with the client. 📞
`

Note added successfully! 🎉
⚡ Why This App? 🚀
Simple & Easy to Use 🎯: The application is designed with simplicity in mind. Just enter the menu option and follow the instructions. It’s beginner-friendly! 👶
File Persistence 💾: Notes are saved on disk, making them available even after closing the program. 📂
Edit & Delete Functionality 🛠️: Notes can be modified or removed as needed, ensuring flexibility. 🔄
🚀 Future Improvements
Search Notes 🔍: Add a search feature to find notes by title or content, so you don’t have to scroll through them manually! 📚
Note Categorization 🗂️: Add categories or tags to better organize the notes by topic. 🏷️
Graphical Interface 🖼️: Implement a graphical user interface (GUI) for easier interaction, for those who prefer a more visual experience! 👨‍💻
Cloud Sync ☁️: Allow the notes to sync across devices with cloud storage support. 🌍
📋 License
This project is licensed under the MIT License - see the LICENSE file for details. ⚖️

💬 Contribute
Feel free to fork this project, submit issues, and make pull requests if you'd like to contribute. Suggestions and improvements are always welcome! 💡

📧 Contact
For any questions, feel free to contact me:

Email: your-email@example.com 📧
GitHub: yourusername 💻
🎉 Conclusion
Thank you for using the Note-Taking Application! We hope this small tool helps you stay organized, jot down your ideas, and never forget an important thought. 📓✨

Don't forget to ⭐️ this repo if you find it helpful, and feel free to contribute with your suggestions or improvements! 🚀

Keep note-taking and stay productive! 💪🌟
