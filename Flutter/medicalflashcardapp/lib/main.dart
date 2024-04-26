// import 'package:flutter/material.dart';

// void main() {
//   runApp(MyApp());
// }

// class MyApp extends StatelessWidget {
//   const MyApp({super.key});

//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       home: Scaffold(
//         appBar: AppBar(
//           backgroundColor: Colors.green,
//           title: const Text("I'm cool and you're not!"),
//         ),
//         floatingActionButton: FloatingActionButton(
//           onPressed: () {
//             print("Hey.");
//           },
//         ),
//       ),
//     );
//   }
// }




import 'dart:io';
import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatelessWidget {
  void _runExecutable() async {
    try {
      await Process.start('C:/Users/PC/Desktop/Coding/MedicalRevisionProgram/Main.exe', []);
    } catch (e) {
      print("Failed to run executable: $e");
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Run Executable Example'),
      ),
      body: Center(
        child: ElevatedButton(
          onPressed: _runExecutable,
          child: Text('Run Executable'),
        ),
      ),
    );
  }
}

