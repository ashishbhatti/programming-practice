//  MongoDB : Crossplatform, opensource, document oriented database management system. It classified as NoSQL Database.
//  It is really fast, really flexible and its crossplatform.


// CREATING COLLECTIONS ; Terminal Commands

// use giraffe  -- Create a database
// db.createCollection("students")   -- Terminal command to create a collection ; Another way to create a collection is to directly enter data
// db.students.drop()   -- Terminal command to delete a collection

// MongoDB uses language called bson, similar to json (javascript object Notification.)



// INSERTING DOCUMENTS

// Data Types
{/*
    string: "String of text",
    int: 405,
    double: 3.565,
    boolean: true, //false
    array: [1, 2, 3]
    onject: {attr1: "attr1", attr2: "attr2"},
    date: new Date("<YYYY-mm-dd>"),
    object_id: <ObjectId>,
    no_value: null

*/}

{/*
Additional Data Types
----------------------

Timestamp
Binary data
Regular expressions
JS Code

*/}


// Inserting into collections : Used to store related info, similar to tables
// A record is called a document

db.students.insertOne({name: "Jack", major: "Biology", gpa: 3.5})  // Allows us to insert one record into the collection, assigns a unique object id

// Allows us to insert one record into the collection, custom object id
db.students.insertOne({_id: 2, name: "Claire", major: "Marketing", gpa: 3.7,
                       awards: ["Valedictorian", "Summa cum laude"] 
                    })  


db.students.insertOne({name: "Evan", major: "Astronomy", gpa: 3.7,
                       grades: [90,88,95,78] 
                    })


db.students.insertOne({name: "Kate", major: "Sociology", gpa: 3.2,
                       contact: {phone: "333-3333", email: "student@school.edu"} 
                    })

db.students.insertOne({name: "Phil", major: "Chemistry", gpa: 2.5,
                       startdate: new Date("2012-08-23")})


db.students.insertMany([
    {name: "Mike", major: "Computer Science", gpa: 2.7},
    {name: "Andrea", major: "Math", gpa: 4.0, awards: ["Summa Cum Laude"]}

                    
])

// FINDING DOCUMENTS 
// Finding and querying records in a collection

db.students.find({})      // Finds all the records in the collection ; example of Query

db.students.find({},{_id: 0})      // Turn id off i.e. don't return id

db.students.find({},{_id: 0}).limit(3)    // Top 3

db.students.find({},{_id: 0}).sort({name: 1})  // Sorts alphabetically by name

db.students.find({},{_id: 0}).sort({gpa: -1, name: 1})   // 1 : Ascending Order, -1: Descending Order

db.students.find({major: "Biology"},{_id: 0})   // Find entries with major biology

db.students.find({major: "Biology", name: "Jack"},{_id: 0})   // First find entries with major biology then filter entries with name Jack out of those // AND Logic


// Final all students who are chemistry majots or named Jack
db.students.find({ $or: [{major: "Chemistry"},{name: "Jack"}]}, {_id: 0})   // OR logic

// Comparison : All students with gpa > 3.5
db.students.find( { gpa: {$gt: 3.5} }, {_id:0})

// Comparison : All students with gpa <= 3.2
db.students.find( { gpa: {$lte: 3.2} }, {_id:0}).sort({gpa:-1})

// $eq, $ne, $lt, $lte, $gt, $gte

// Find if in a list   // $nin means not in
db.students.find( { name: {$in : [ "Kate", "Claire" ] } }, {_id:0} )

// Grab the objects having specific fields
db.students.find( { awards : {$exists: true} }, {_id:0} )

// Because MongoDB is so flexible, same fields can have different data types
// In those scenarios you can grab all the objects ehich have a particular data type
db.students.find( { name : {$type: 2} }, {_id:0} )
// 2 stands for strings in BSON

// Grabbing entries with a particular array element; here with 0th element = 90 in grades array
db.students.find( { "grades.0" : 90 }, {_id:0} )

// Finding all the objects which have an array element 
db.students.find( { grades : {$elemMatch: {$gte: 80} } }, {_id:0} )

// Finding all the objects which has a particular array of some size 
db.students.find( { grades : {$size: 4 } }, {_id:0} )



// UPDATING AND DELETING DOCUMENTS
// Updating and deleting records in mongobd collection 


// Updating only one record in the database which matches the filter
db.students.updateOne(
    {major: "Chemistry"},    // filter
    {
        $set:
            {major: "Biology"}
    }
)


// This will update only the first occurence of the filter
db.students.updateOne(
    {major: "Biology"},    // filter
    {
        $set:
            {major: "Bio"}
    }
)


// Updates all the matched occurences
db.students.updateMany(
    {major: "Bio"},
    {
        $set:
            {major: "Biology"}
    }
)


// Replacing with a new entry
db.students.replaceOne(
    {major: "Biology"},
    {name : "new name", major : "new major", gpa : 4.0}
)


// Deleting
db.student.deleteMany({})    // Deletes everything

db.students.deleteMany({gpa : {$gte : 3.5}})   // Delete entries with gpa >= 3.5

db.students.deleteOne({major : "Biology"})


// BULK ACTIONS
// Bulk rights and MongoDB ; Bulk right is a special function where we combine a bunch of db requests into one request.
// Can only be done on one single collection

db.students.bulkWrite(
    [
        { insertOne : 
            {
                "document" : {name: "Andrew", major: "Architecture", gpa: 3.2}
            }
        },
        { insertOne : 
            {
                "document" : {name: "Terry", major: "Math", gpa: 3.8}

            }
        },
        { updateOne : 
            {
                filter : { name : "Terry" },
                update : { $set : {gpa : 4.0} }
            }
        },
        { deleteOne : 
            { filter : { name : "Kate"} }
        },
        { replaceOne :
            {
                filter : { name : "Mike" },
                replacement : { name : "Genny", major: "Counsling", gpa : 1.9}
            }
        
        }
    ]
);



// TEXT INDEXING
// Basically a special thing to put on a collection that allows us to do text searching on that collection

// Creating a new collection i.e. table
// fisrt we inisert these documents into the collection and then we will be able to create a text index on names and description fields, 
// hence we will be able to query the database with one or two words.....so like setting a search bar
db.stores.insertMany(
    [
        { _id: 1, name: "Java Hut", description: "Coffee and cakes"},
        { _id: 2, name: "Burger Buns", description: "Gourmet hamburgers"},
        { _id: 3, name: "Coffee Shop", description: "Just coffee"},
        { _id: 4, name: "Clothes Clothes Clothes", description: "Discount clothing"},
        { _id: 5, name: "Java Shopping", description: "Indonesian goods"}
    ]

)

//Creating text index 
db.stores.createIndex( {name : "text", description : "text"} )   // put the names of the fields in collection on which you want to put the text index; "text" stands here for text index


//Now searching
db.stores.find( { $text: { $search: "Coffee" } } )    // Not case sensitive


db.stores.find( { $text: { $search: "Java Hut Coffee" } } )   // Searches for Java, Hut, Coffee

// Adding text score
// Ranks the returned things on how closely they were related to search term
db.stores.find(
    { $text: { $search: "Java Hut Coffee" } },
    { score: { $meta: "textScore"} }
)

//sorting the search terms depending on score
db.stores.find(
    { $text: { $search: "Java Hut Coffee" } },
    { score: { $meta: "textScore"} }
).sort( {score: {$meta: "textScore"}} )



// AGGREGATION : Common task for any database
// process data records and return computed results. So we can get info that is not necassarily stored in the collection. But we can do computations to get the info.

//Creating a new collection
db.purchase_orders.insertMany(
    [
        {product: "toothbrush", total: 4.75, customer: "Mike" },
        {product: "guitar", total: 199.99, customer: "Tom"},
        {product: "milk", total: 11.33, customer: "Mike"},
        {product: "pizza", total: 8.50, customer: "Karen"},
        {product: "toothbrush", total: 4.75, customer: "Karen"},
        {product: "pizza", total: 4.75, customer: "Dave"},
        {product: "toothbrush", total: 4.75, customer: "Mike"}
    ]
)


// find out how many toothbrushes were sold
db.purchase_orders.count({product : "toothbrush"})

//find a list of all products sold
db.purchase_orders.find({ product : {$exists : true}})  // but this returns all the documents even if the product is repeated

db.purchase_orders.distinct("product")   // Returns a list


// find the total amount of money spent by each customer
db.purchase_orders.aggregate(
    [
        {$match: {} },   // filter ; here filtering everything
        {$group: {_id: "$customer", total: {$sum: "$total"}}}      // defining the structure of info we want to get back
    ]
)


// find the total amount of money spent on each product
db.purchase_orders.aggregate(
    [
        {$match: {} },   // filter ; here filtering everything
        {$group: {_id: "$product", total: {$sum: "$total"}}}      // defining the structure of info we want to get back
    ]
)




// sorting and find the total amount of money spent on each product
db.purchase_orders.aggregate(
    [
        {$match: {} },   // filter ; here filtering everything
        {$group: {_id: "$product", total: {$sum: "$total"}}},// defining the structure of info we want to get back
        {$sort : {total:-1}}      
    ]
)


// Filtering, sorting and find the total amount of money spent by each customer
db.purchase_orders.aggregate(
    [
        {$match: {customer : {$in : ["Mike", "Karen"]}} },   // filter ; here filtering everything
        {$group: {_id: "$customer", total: {$sum: "$total"}}},// defining the structure of info we want to get back
        {$sort : {total:-1}}      
    ]
)