#include <mongoc/mongoc.h>
#include <bson/bson.h>
#include <iostream>

void init() {
    mongoc_init();
}

void cleanup() {
    mongoc_cleanup();
}

void create_document(mongoc_collection_t *collection) {
    bson_t *document = bson_new();
    BSON_APPEND_UTF8(document, "name", "Alice");
    BSON_APPEND_INT32(document, "age", 30);

    bson_error_t error;
    if (!mongoc_collection_insert_one(collection, document, nullptr, nullptr, &error)) {
        std::cerr << "Insert failed: " << error.message << std::endl;
    } else {
        std::cout << "Document inserted successfully." << std::endl;                                                                }

    bson_destroy(document);
}
void read_documents(mongoc_collection_t *collection) {
    bson_t *query = bson_new();
    mongoc_cursor_t *cursor = mongoc_collection_find_with_opts(collection, query, nullptr, nullptr);
    const bson_t *doc;
    bson_error_t error; // Declare the error variable here

    while (mongoc_cursor_next(cursor, &doc)) {
        char *str = bson_as_canonical_extended_json(doc, nullptr);
        std::cout << "Document: " << str << std::endl;
        bson_free(str);
    }

    if (mongoc_cursor_error(cursor, &error)) {
        std::cerr << "Cursor error: " << error.message << std::endl;
    }

    bson_destroy(query);
    mongoc_cursor_destroy(cursor);
}
void update_document(mongoc_collection_t *collection) {
    bson_t *filter = bson_new();
    BSON_APPEND_UTF8(filter, "name", "Alice");

    bson_t *update = bson_new();
    bson_t *set = bson_new();
    BSON_APPEND_INT32(set, "age", 31);
    BSON_APPEND_DOCUMENT(update, "$set", set);

    bson_error_t error;
    if (!mongoc_collection_update_one(collection, filter, update, nullptr, nullptr, &error)) {
        std::cerr << "Update failed: " << error.message << std::endl;
    } else {
        std::cout << "Document updated successfully." << std::endl;
    }

    bson_destroy(filter);
    bson_destroy(update);
    bson_destroy(set);
}

void delete_document(mongoc_collection_t *collection) {
    bson_t *filter = bson_new();
    BSON_APPEND_UTF8(filter, "name", "Alice");

    bson_error_t error;
    if (!mongoc_collection_delete_one(collection, filter, nullptr, nullptr, &error)) {
        std::cerr << "Delete failed: " << error.message << std::endl;
    } else {
        std::cout << "Document deleted successfully." << std::endl;
    }

    bson_destroy(filter);
}
int main() {
    init();

    mongoc_client_t *client = mongoc_client_new("mongodb://localhost:27017");
    mongoc_collection_t *collection = mongoc_client_get_collection(client, "testdb", "testcollection");

    create_document(collection);
    read_documents(collection);
    update_document(collection);
    read_documents(collection);
    delete_document(collection);
    read_documents(collection);

    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    cleanup();

    return 0;
}
//g++ -o democrud fullcrud.cpp $(pkg-config --cflags --libs libmongoc-1.0 libbson-1.0) 