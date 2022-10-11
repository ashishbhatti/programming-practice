// The line imports the package which renders the widgets in the material them
// of Google
import 'package:flutter/material.dart';

// main function is the entry point in any dart code or in this case flutter application
void main() {
  // runApp is a function which takes an instance of a Widget as input and renders it on screen
  // meaning that it takes the Widget object and writes to pixels on screen
  runApp(const MyApp());
}

// This is the main App widget which is just an extension of stateless widget
// meaning it doesn't store the state of the app
// This widget must contain all the other widgets which our app needs
class MyApp extends StatelessWidget {
  // This is a constructor, it takes an optional parameter of type Key,
  // with an initializer list
  const MyApp({Key? key}) : super(key: key);

  // This is the main method in a widget, this method returns a Widget object
  // which provides the configuration information of the widget
  // meaning how will the widget look like on screen
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Flutter Build Method Demo',
      home: Center(child: Text('Hello Sir!')),
    );
  }
}
