-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 24, 2019 at 01:21 PM
-- Server version: 10.4.6-MariaDB
-- PHP Version: 7.3.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `quiz`
--

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE `courses` (
  `id` int(11) NOT NULL,
  `CourseID` varchar(10) NOT NULL,
  `CourseTitle` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`id`, `CourseID`, `CourseTitle`) VALUES
(1, 'CSE 3107', 'Applied Statistics and Queuing Theory'),
(2, 'CSE 1100', 'Computer Fundamentals and Ethics'),
(3, 'CSE 1101', 'Computer Programming'),
(4, 'CSE 1102', 'Sessional Based On CSE 1101'),
(5, 'CSE 3105', 'Software Engineering'),
(6, 'EEE 1151', 'Basic Electrical Engineering'),
(7, 'EEE 1152', 'Sessional Based On EEE 1151'),
(8, 'CSE 3109', 'Microprocessors and Assembly Language'),
(9, 'CSE 3101', 'Database System'),
(10, 'Hum 2113', 'Industrial Management and Accountancy');

-- --------------------------------------------------------

--
-- Table structure for table `question`
--

CREATE TABLE `question` (
  `QuestionID` int(11) NOT NULL,
  `QuestionText` varchar(200) NOT NULL,
  `Option1` varchar(100) NOT NULL,
  `Option2` varchar(100) NOT NULL,
  `Option3` varchar(100) NOT NULL,
  `Option4` varchar(100) NOT NULL,
  `CorrectOption` varchar(1) NOT NULL,
  `CourseID` varchar(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `question`
--

INSERT INTO `question` (`QuestionID`, `QuestionText`, `Option1`, `Option2`, `Option3`, `Option4`, `CorrectOption`, `CourseID`) VALUES
(2, 'Which one is an output device?', 'keyboeard', 'mouse', 'monitor', 'scanner', '3', '2'),
(3, 'The instructions that tell the computer what to do and how to do it:', 'Software', 'Hardware', 'Mouse', 'Printer', '1', '2'),
(4, 'The heart (and brains) of the computer is the: ', 'Hard drive', 'Motherboard', 'CPU', 'RAM', '3', '2'),
(5, 'When you save a file, it is permanently saved on the: ', 'CPU', 'Hard drive', 'Ram', 'Monitor', '2', '2'),
(6, 'Which one is a co-processor?', '8086', '8087', '8257', '8088', '2', '8'),
(7, 'Which one is a DMA controller?', '8086', '8087', '8088', '8257', '4', '8'),
(8, 'Which one is a general purpose register?', 'AX', 'BP', 'SI', 'Flag', '1', '8'),
(9, 'Which command is illegal?', 'MOV AH, 2', 'MOV CX, [SI]', 'INC DX', 'INT 21h', '2', '8'),
(11, 'Which one is an input device?', 'keyboard', 'monitor', 'printer', 'speaker', '1', '2');

-- --------------------------------------------------------

--
-- Table structure for table `quiz_data`
--

CREATE TABLE `quiz_data` (
  `QuizID` int(11) NOT NULL,
  `UserID` varchar(7) NOT NULL,
  `NumberOfQuestions` varchar(2) NOT NULL,
  `SuccessfullAttempts` varchar(2) NOT NULL,
  `CourseID` varchar(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `quiz_data`
--

INSERT INTO `quiz_data` (`QuizID`, `UserID`, `NumberOfQuestions`, `SuccessfullAttempts`, `CourseID`) VALUES
(2, '1603013', '5', '5', '2'),
(3, '1603013', '3', '3', '8'),
(4, '1603013', '4', '3', '8'),
(5, '1603013', '5', '0', '2'),
(6, '1603013', '5', '0', '2'),
(8, '1603013', '5', '5', '2');

-- --------------------------------------------------------

--
-- Table structure for table `userinfo`
--

CREATE TABLE `userinfo` (
  `IDbyDatabase` int(11) NOT NULL,
  `FirstName` varchar(25) NOT NULL,
  `LastName` varchar(15) NOT NULL,
  `StudentTeacherID` varchar(7) NOT NULL,
  `email` varchar(45) NOT NULL,
  `UserType` varchar(7) NOT NULL,
  `UserPassword` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `userinfo`
--

INSERT INTO `userinfo` (`IDbyDatabase`, `FirstName`, `LastName`, `StudentTeacherID`, `email`, `UserType`, `UserPassword`) VALUES
(1, 'Riyad Morshed', 'Shoeb', '1603013', 'rmshoebne14@gmail.com', 'student', '1603013'),
(2, 'Mrinmoy', 'Mondal', '1603012', 'mrinmoy@gmail.com', 'student', '1603012'),
(3, 'Professor Dr.', 'Shahid Uz Zaman', '12345', 'profzaman@gmail.com', 'teacher', '12345');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `question`
--
ALTER TABLE `question`
  ADD PRIMARY KEY (`QuestionID`);

--
-- Indexes for table `quiz_data`
--
ALTER TABLE `quiz_data`
  ADD PRIMARY KEY (`QuizID`);

--
-- Indexes for table `userinfo`
--
ALTER TABLE `userinfo`
  ADD PRIMARY KEY (`IDbyDatabase`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `courses`
--
ALTER TABLE `courses`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `question`
--
ALTER TABLE `question`
  MODIFY `QuestionID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `quiz_data`
--
ALTER TABLE `quiz_data`
  MODIFY `QuizID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `userinfo`
--
ALTER TABLE `userinfo`
  MODIFY `IDbyDatabase` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
