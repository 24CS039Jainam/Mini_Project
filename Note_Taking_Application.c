#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_CONTENT_LEN 1000
#define FILENAME "notes.txt"

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
} Note;

void addNote();
void viewNotes();
void editNote();
void deleteNote();
int getNewNoteId();
void saveNote(Note note);
void listAllNotes();

int main() {
    int choice;
    while (1) {
        printf("\n--- Note-Taking Application ---\n");
        printf("1. Add Note\n");
        printf("2. View All Notes\n");
        printf("3. Edit Note\n");
        printf("4. Delete Note\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                editNote();
                break;
            case 4:
                deleteNote();
                break;
            case 5:
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addNote() {
    Note note;
    note.id = getNewNoteId();
    printf("Enter title of the note: ");
    getchar();
    fgets(note.title, MAX_TITLE_LEN, stdin);
    note.title[strcspn(note.title, "\n")] = 0;

    printf("Enter content of the note (type ` on a new line to finish):\n");

    int index = 0;
    char ch;
    while (index < MAX_CONTENT_LEN - 1) {
        ch = getchar();
        if (ch == '`' && (index == 0 || note.content[index - 1] == '\n')) {
            note.content[index - 1] = '\0';
            break;
        }
        note.content[index++] = ch;
    }
    note.content[index] = '\0';

    saveNote(note);
    printf("Note added successfully!\n");
}

void viewNotes() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No notes found.\n");
        return;
    }
    Note note;
    printf("\n--- All Notes ---\n");
    while (fread(&note, sizeof(Note), 1, file)) {
        printf("ID: %d\nTitle: %s\nContent: %s\n", note.id, note.title, note.content);
        printf("----------------------\n");
    }
    fclose(file);
}

void editNote() {
    int id, found = 0;
    Note note;
    printf("Enter the ID of the note to edit: ");
    scanf("%d", &id);

    FILE *file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        printf("No notes found.\n");
        return;
    }

    while (fread(&note, sizeof(Note), 1, file)) {
        if (note.id == id) {
            found = 1;
            printf("Editing note with ID %d\n", id);
            printf("Current Title: %s\n", note.title);
            printf("Enter new title: ");
            getchar();
            fgets(note.title, MAX_TITLE_LEN, stdin);
            note.title[strcspn(note.title, "\n")] = 0;

            printf("Enter new content (type ` on a new line to finish):\n");

            int index = 0;
            char ch;
            while (index < MAX_CONTENT_LEN - 1) {
                ch = getchar();
                if (ch == '`' && (index == 0 || note.content[index - 1] == '\n')) {
                    note.content[index - 1] = '\0';
                    break;
                }
                note.content[index++] = ch;
            }
            note.content[index] = '\0';

            fseek(file, -sizeof(Note), SEEK_CUR);
            fwrite(&note, sizeof(Note), 1, file);
            printf("Note edited successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Note with ID %d not found.\n", id);
    }
    fclose(file);
}

void deleteNote() {
    int id, found = 0;
    Note note;
    printf("Enter the ID of the note to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(FILENAME, "rb");
    FILE *temp = fopen("temp.txt", "wb");

    if (file == NULL) {
        printf("No notes found.\n");
        return;
    }

    while (fread(&note, sizeof(Note), 1, file)) {
        if (note.id == id) {
            found = 1;
            printf("Note with ID %d deleted successfully!\n", id);
        } else {
            fwrite(&note, sizeof(Note), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (!found) {
        printf("Note with ID %d not found.\n", id);
    }
}

int getNewNoteId() {
    FILE *file = fopen(FILENAME, "rb");
    Note note;
    int maxId = 0;

    if (file == NULL) return 1;

    while (fread(&note, sizeof(Note), 1, file)) {
        if (note.id > maxId) {
            maxId = note.id;
        }
    }
    fclose(file);
    return maxId + 1;
}

void saveNote(Note note) {
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&note, sizeof(Note), 1, file);
    fclose(file);
}
