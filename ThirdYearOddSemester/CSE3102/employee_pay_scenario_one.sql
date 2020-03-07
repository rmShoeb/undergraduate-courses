-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 24, 2019 at 01:20 PM
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
-- Database: `employee_pay_scenario_one`
--

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `dept_id` int(11) NOT NULL,
  `dept_name` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`dept_id`, `dept_name`) VALUES
(1, 'Engineering'),
(2, 'GIS'),
(3, 'Admin'),
(4, 'Editor'),
(5, 'Labor');

-- --------------------------------------------------------

--
-- Table structure for table `employee`
--

CREATE TABLE `employee` (
  `emp_id` int(11) NOT NULL,
  `emp_name` varchar(45) NOT NULL,
  `dept_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `employee`
--

INSERT INTO `employee` (`emp_id`, `emp_name`, `dept_id`) VALUES
(1603001, 'Shegufa', 1),
(1603002, 'Nasif', 2),
(1603003, 'Hasib', 3),
(1603004, 'Muntashir', 4),
(1603005, 'Shamiul', 5),
(1603006, 'Rakib', 1),
(1603007, 'Yamin', 2),
(1603008, 'Siam', 3),
(1603009, 'Mustafiz', 4),
(1603011, 'Fatin', 5),
(1603012, 'Mrinmoy', 1),
(1603013, 'Riyad', 2),
(1603015, 'Nahid', 4),
(1603016, 'Mridul', 5),
(1603017, 'Nur', 1),
(1603018, 'Azmal', 2),
(1603019, 'Sporsho', 3),
(1603020, 'Shohanur', 4),
(1603021, 'Abir', 5),
(1603022, 'Utshob', 3);

-- --------------------------------------------------------

--
-- Table structure for table `paydetails`
--

CREATE TABLE `paydetails` (
  `emp_id` int(11) NOT NULL,
  `dept_id` int(11) NOT NULL,
  `basic` int(11) NOT NULL,
  `DOJ` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `paydetails`
--

INSERT INTO `paydetails` (`emp_id`, `dept_id`, `basic`, `DOJ`) VALUES
(1603001, 1, 10000, '2016-12-02'),
(1603002, 2, 9000, '2016-12-02'),
(1603003, 3, 7000, '2016-12-02'),
(1603004, 4, 5000, '2016-12-02'),
(1603005, 5, 8500, '2016-12-02'),
(1603006, 1, 7500, '2016-12-02'),
(1603007, 2, 6000, '2016-12-02'),
(1603008, 3, 6500, '2016-12-02'),
(1603009, 4, 5500, '2016-12-02'),
(1603011, 5, 6600, '2016-12-05'),
(1603012, 1, 5000, '2016-12-05'),
(1603013, 2, 9000, '2016-12-05'),
(1603015, 4, 5000, '2016-12-05'),
(1603016, 5, 7000, '2016-12-05'),
(1603017, 1, 8500, '2016-12-05'),
(1603018, 2, 9000, '2016-12-05'),
(1603019, 3, 6500, '2016-12-16'),
(1603020, 4, 7500, '2016-12-16'),
(1603021, 5, 9500, '2016-12-16'),
(1603022, 3, 5500, '2016-12-16');

-- --------------------------------------------------------

--
-- Table structure for table `payroll`
--

CREATE TABLE `payroll` (
  `emp_id` int(11) NOT NULL,
  `pay_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `payroll`
--

INSERT INTO `payroll` (`emp_id`, `pay_date`) VALUES
(1603001, '2019-02-01'),
(1603002, '2019-02-01'),
(1603003, '2019-02-01'),
(1603004, '2019-02-01'),
(1603005, '2019-02-01'),
(1603006, '2019-02-01'),
(1603007, '2019-02-01'),
(1603008, '2019-02-01'),
(1603009, '2019-02-01'),
(1603011, '2019-02-01'),
(1603012, '2019-02-01'),
(1603013, '2019-02-01'),
(1603015, '2019-02-01'),
(1603016, '2019-02-01'),
(1603017, '2019-02-01'),
(1603018, '2019-02-01'),
(1603019, '2019-02-01'),
(1603020, '2019-02-01'),
(1603021, '2019-02-01'),
(1603022, '2019-02-01');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`dept_id`);

--
-- Indexes for table `employee`
--
ALTER TABLE `employee`
  ADD PRIMARY KEY (`emp_id`),
  ADD KEY `dept_id` (`dept_id`);

--
-- Indexes for table `paydetails`
--
ALTER TABLE `paydetails`
  ADD KEY `emp_id` (`emp_id`),
  ADD KEY `dept_id` (`dept_id`);

--
-- Indexes for table `payroll`
--
ALTER TABLE `payroll`
  ADD KEY `emp_id` (`emp_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `employee`
--
ALTER TABLE `employee`
  ADD CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`dept_id`) REFERENCES `department` (`dept_id`);

--
-- Constraints for table `paydetails`
--
ALTER TABLE `paydetails`
  ADD CONSTRAINT `paydetails_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`),
  ADD CONSTRAINT `paydetails_ibfk_2` FOREIGN KEY (`dept_id`) REFERENCES `department` (`dept_id`);

--
-- Constraints for table `payroll`
--
ALTER TABLE `payroll`
  ADD CONSTRAINT `payroll_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
