-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 24, 2019 at 01:22 PM
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
-- Database: `student_rental_library`
--

-- --------------------------------------------------------

--
-- Table structure for table `book`
--

CREATE TABLE `book` (
  `book_no` varchar(10) NOT NULL,
  `book_name` varchar(255) NOT NULL,
  `author` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `book`
--

INSERT INTO `book` (`book_no`, `book_name`, `author`) VALUES
('B001', 'Database Design', 'Adrienne Watt'),
('B002', 'Databases, Types, and the Relational Model: The Third Manifesto', 'Hugh Darwen '),
('B003', 'Database Lifecycle Management: Achieving Continuous Delivery', 'Matthew Skelton'),
('B004', 'Theory of Relational Databases', 'David Maier'),
('B005', 'Foundations of Databases: The Logical Level', 'Serge Abiteboul'),
('B006', 'Database Fundamentals', 'Liviu Perniu'),
('B007', 'Concurrency Control and Recovery in Database Systems', 'Nathan Goodman '),
('B008', 'Developing Time-Oriented Database Applications in SQL', 'Richard T. Snodgrass'),
('B009', 'Database Design and Implementation using Oracle SQL', 'Howard Gould'),
('B010', 'Relational Data Model, Normalisation and Effective Database Design', 'Tony Marston '),
('B011', 'Database Systems and Structures', 'Osmar R. Zaiane'),
('B012', 'Database Design with UML and SQL', 'Tom Jewett'),
('B013', 'Temporal Database Management', 'Christian S. Jensen'),
('B014', 'Making Sense of Stream Processing: Behind Apache Kafka', 'Martin Kleppmann'),
('B015', 'Information Modeling: Specification and Implementation', 'David Edmond '),
('B016', 'Category Theory for the Sciences', 'David I. Spivak'),
('B017', 'Modeling with Data: Tools and Techniques for Scientific Computing', 'Ben Klemens'),
('B018', 'Data-Oriented Design', 'Richard Fabian'),
('B019', 'Introduction to Information Retrieval', 'Christopher Manning'),
('B020', 'Multimedia Fingerprinting Forensics for Traitor Tracing', 'K. J. Liu'),
('B021', 'Computer Networks', 'Tanenbaum'),
('B022', 'Operating Systems: Design and Implementation', 'Tanenbaum'),
('B023', 'Modern Operating Systems', 'Tanenbaum'),
('B024', 'Distributed Operating Systems', 'Tanenbaum'),
('B025', 'Distributed Systems: Principles and Paradigms', 'Tanenbaum'),
('B30', 'GolpoGuccho', 'Rabindarnath Tagore');

-- --------------------------------------------------------

--
-- Table structure for table `iss_rec`
--

CREATE TABLE `iss_rec` (
  `iss_no` int(11) NOT NULL,
  `iss_date` date NOT NULL,
  `mem_no` varchar(10) NOT NULL,
  `book_no` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `iss_rec`
--

INSERT INTO `iss_rec` (`iss_no`, `iss_date`, `mem_no`, `book_no`) VALUES
(13, '2019-08-28', 'M01', 'B001'),
(14, '2019-08-28', 'M01', 'B003'),
(15, '2019-08-28', 'M01', 'B005'),
(16, '2019-08-28', 'M02', 'B002'),
(17, '2019-08-28', 'M03', 'B009'),
(18, '2019-08-28', 'M06', 'B004'),
(19, '2019-08-28', 'M10', 'B020'),
(20, '2019-08-28', 'M10', 'B019'),
(21, '2019-08-28', 'M06', 'B011'),
(22, '2019-08-28', 'M07', 'B010'),
(23, '2019-08-28', 'M09', 'B015'),
(24, '2019-08-28', 'M09', 'B013'),
(26, '2019-08-28', 'M02', 'B021'),
(27, '2019-08-28', 'M05', 'B023'),
(28, '2019-08-28', 'M06', 'B023'),
(30, '2019-08-29', 'M10', 'B024'),
(31, '2019-08-29', 'M02', 'B011'),
(32, '2019-08-29', 'M03', 'B021'),
(33, '2019-08-29', 'M04', 'B001'),
(34, '2019-08-31', 'M11', 'B001'),
(35, '2019-08-31', 'M11', 'B013'),
(36, '2019-08-31', 'M09', 'B023'),
(37, '2019-08-31', 'M05', 'B011'),
(38, '2019-08-31', 'M12', 'B021');

--
-- Triggers `iss_rec`
--
DELIMITER $$
CREATE TRIGGER `before_iss_rec_insert` BEFORE INSERT ON `iss_rec` FOR EACH ROW BEGIN
    	IF (SELECT COUNT(*) FROM iss_rec WHERE NEW.mem_no=iss_rec.mem_no) = 3
        	THEN
            	SIGNAL SQLSTATE '45001'
                SET MESSAGE_TEXT = "You have already borrowed 3 books.";
        END IF;
        SET NEW.iss_date = CURRENT_DATE();
    END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `membership`
--

CREATE TABLE `membership` (
  `mem_no` varchar(15) NOT NULL,
  `stud_no` varchar(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `membership`
--

INSERT INTO `membership` (`mem_no`, `stud_no`) VALUES
('M01', 'C1603001'),
('M02', 'C1603002'),
('M03', 'C1603003'),
('M04', 'C1603004'),
('M05', 'C1603006'),
('M06', 'C1603007'),
('M07', 'C1603008'),
('M08', 'C1603009'),
('M09', 'C1603011'),
('M10', 'C1603012'),
('M11', 'C1603016'),
('M12', 'C1603017');

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `stud_no` varchar(8) NOT NULL,
  `stude_name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`stud_no`, `stude_name`) VALUES
('C1503013', 'Riyad'),
('C1603001', 'Shegufa Rob'),
('C1603002', 'Nasif Raihan'),
('C1603003', 'Hasib'),
('C1603004', 'Muntahir Akon'),
('C1603006', 'Rakibul Hasan'),
('C1603007', 'Yamin Hoque'),
('C1603008', 'Md Al Siam'),
('C1603009', 'Mustafizur Rahman'),
('C1603011', 'Fatin Faiaz Isty'),
('C1603012', 'Mrinmoy Mondal'),
('C1603013', 'Riyad Morshed Shoeb'),
('C1603015', 'Nahid Sadik'),
('C1603016', 'Mridul Sayed'),
('C1603017', 'Nur Afroz'),
('C1603018', 'Azmal Awasaf');

--
-- Triggers `student`
--
DELIMITER $$
CREATE TRIGGER `before_student_insert` BEFORE INSERT ON `student` FOR EACH ROW BEGIN
    IF(NEW.stud_no NOT LIKE "C%")
    	THEN
        	SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Student no must start with C';
    END IF;
END
$$
DELIMITER ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `book`
--
ALTER TABLE `book`
  ADD PRIMARY KEY (`book_no`);

--
-- Indexes for table `iss_rec`
--
ALTER TABLE `iss_rec`
  ADD PRIMARY KEY (`iss_no`),
  ADD KEY `mem_no` (`mem_no`),
  ADD KEY `book_no` (`book_no`);

--
-- Indexes for table `membership`
--
ALTER TABLE `membership`
  ADD PRIMARY KEY (`mem_no`),
  ADD KEY `stud_no` (`stud_no`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`stud_no`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `iss_rec`
--
ALTER TABLE `iss_rec`
  MODIFY `iss_no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=39;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `iss_rec`
--
ALTER TABLE `iss_rec`
  ADD CONSTRAINT `iss_rec_ibfk_1` FOREIGN KEY (`mem_no`) REFERENCES `membership` (`mem_no`),
  ADD CONSTRAINT `iss_rec_ibfk_2` FOREIGN KEY (`book_no`) REFERENCES `book` (`book_no`);

--
-- Constraints for table `membership`
--
ALTER TABLE `membership`
  ADD CONSTRAINT `membership_ibfk_1` FOREIGN KEY (`stud_no`) REFERENCES `student` (`stud_no`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
