-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 11, 2019 at 07:40 PM
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
-- Database: `huon_con`
--

-- --------------------------------------------------------

--
-- Table structure for table `address`
--

CREATE TABLE `address` (
  `emp_id` varchar(10) NOT NULL,
  `street_no` varchar(10) NOT NULL,
  `street_name` varchar(25) NOT NULL,
  `city` varchar(15) NOT NULL,
  `zip_code` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `address`
--

INSERT INTO `address` (`emp_id`, `street_no`, `street_name`, `city`, `zip_code`) VALUES
('1603001', 'S_001', 'Talaimari', 'Rajshahi', 6200),
('1603002', 'S_002', 'Talaimari', 'Rajshahi', 6201),
('1603003', 'S_003', 'Talaimari', 'Rajshahi', 6202),
('1603004', 'S_004', 'Talaimari', 'Rajshahi', 6203),
('1603005', 'S_001', 'Talaimari', 'Rajshahi', 6204),
('1603006', 'S_002', 'Talaimari', 'Rajshahi', 6200),
('1603007', 'S_003', 'Talaimari', 'Rajshahi', 6201),
('1603008', 'S_004', 'Talaimari', 'Rajshahi', 6202),
('1603009', 'S_001', 'Talaimari', 'Rajshahi', 6203),
('1603011', 'S_002', 'Talaimari', 'Rajshahi', 6204),
('1603012', 'S_003', 'Talaimari', 'Rajshahi', 6200),
('1603013', 'S_004', 'Talaimari', 'Rajshahi', 6201),
('1603015', 'S_001', 'Talaimari', 'Rajshahi', 6202),
('1603016', 'S_002', 'Talaimari', 'Rajshahi', 6203),
('1603017', 'S_003', 'Talaimari', 'Rajshahi', 6204),
('1603018', 'S_004', 'Talaimari', 'Rajshahi', 6200),
('1603019', 'S_001', 'Talaimari', 'Rajshahi', 6201),
('1603020', 'S_002', 'Talaimari', 'Rajshahi', 6202),
('1603021', 'S_003', 'Talaimari', 'Rajshahi', 6203),
('1603022', 'S_004', 'Talaimari', 'Rajshahi', 6204),
('1603023', 'S_001', 'Talaimari', 'Rajshahi', 6200),
('1603030', 'S_004', 'Talaimari', 'Rajshahi', 6201);

-- --------------------------------------------------------

--
-- Table structure for table `dept`
--

CREATE TABLE `dept` (
  `dept_id` varchar(10) NOT NULL,
  `dept_name` varchar(15) NOT NULL,
  `dept_location` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dept`
--

INSERT INTO `dept` (`dept_id`, `dept_name`, `dept_location`) VALUES
('001', 'Engineering', 'Canberra'),
('002', 'Foreman', 'Googong'),
('003', 'Labor', 'Canberra'),
('004', 'Caretaker', 'Googong'),
('005', 'Carpenter', 'Canberra'),
('006', 'Driver', 'Googong');

-- --------------------------------------------------------

--
-- Table structure for table `employee`
--

CREATE TABLE `employee` (
  `emp_id` varchar(10) NOT NULL,
  `emp_name` varchar(45) NOT NULL,
  `dept_id` varchar(10) NOT NULL,
  `type_of_work` varchar(1) NOT NULL,
  `hourly_rate` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `employee`
--

INSERT INTO `employee` (`emp_id`, `emp_name`, `dept_id`, `type_of_work`, `hourly_rate`) VALUES
('1603001', 'Shegufa', '001', 'F', NULL),
('1603002', 'Nasif', '002', 'F', NULL),
('1603003', 'Hasib', '003', 'P', 45),
('1603004', 'Muntashir', '004', 'F', NULL),
('1603005', 'Shamiul', '005', 'P', 26),
('1603006', 'Rakib', '006', 'P', 59),
('1603007', 'Yamin', '001', 'F', NULL),
('1603008', 'Siam', '002', 'F', NULL),
('1603009', 'Mustafiz', '003', 'P', 55),
('1603011', 'Fatin', '004', 'F', NULL),
('1603012', 'Mrinmoy', '005', 'P', 30),
('1603013', 'Riyad', '001', 'F', NULL),
('1603014', 'Jarir', '006', 'P', 26),
('1603015', 'Nahid', '002', 'F', NULL),
('1603016', 'Mridul', '003', 'F', NULL),
('1603017', 'Shithi', '004', 'F', NULL),
('1603018', 'Azmal', '005', 'F', NULL),
('1603019', 'Sporsho', '006', 'P', 45),
('1603020', 'Shohanur', '001', 'P', 40),
('1603021', 'Abir', '002', 'F', NULL),
('1603022', 'Utshob', '003', 'F', NULL),
('1603023', 'Sabu', '004', 'F', NULL),
('1603024', 'Asha', '005', 'F', NULL),
('1603025', 'Durlov', '006', 'F', NULL),
('1603026', 'Naj', '001', 'F', NULL),
('1603028', 'Soykot', '005', 'P', 30),
('1603030', 'Bonny', '002', 'P', 60);

--
-- Triggers `employee`
--
DELIMITER $$
CREATE TRIGGER `before_employee_insert` BEFORE INSERT ON `employee` FOR EACH ROW BEGIN
    	IF((NEW.type_of_work != 'F') AND (NEW.type_of_work != 'P'))
        	THEN
            	SIGNAL SQLSTATE '45000'
                SET MESSAGE_TEXT = 'Type of work can be either F or P.';
        END IF;
    	IF((NEW.type_of_work = 'P') AND (NEW.hourly_rate NOT BETWEEN 25 AND 60))
        	THEN
            	SIGNAL SQLSTATE '45001'
                SET MESSAGE_TEXT = 'Hourly rate have to be between $25 and $60.';
        END IF;
    END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Stand-in structure for view `employee_info`
-- (See below for the actual view)
--
CREATE TABLE `employee_info` (
`Name` varchar(45)
,`Department` varchar(15)
,`type_of_work` varchar(1)
,`Basic` int(11)
,`allowance` decimal(13,2)
,`deduction` decimal(13,2)
,`Salary` int(11)
);

-- --------------------------------------------------------

--
-- Table structure for table `ft_pt_work`
--

CREATE TABLE `ft_pt_work` (
  `project_id` varchar(5) NOT NULL,
  `emp_id` varchar(10) NOT NULL,
  `dept_id` varchar(10) NOT NULL,
  `num_of_hours` int(11) NOT NULL,
  `works_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ft_pt_work`
--

INSERT INTO `ft_pt_work` (`project_id`, `emp_id`, `dept_id`, `num_of_hours`, `works_date`) VALUES
('001', '1603001', '001', 8, '2019-08-01'),
('002', '1603001', '001', 7, '2019-08-02'),
('003', '1603001', '001', 8, '2019-08-03'),
('001', '1603001', '001', 7, '2019-08-04'),
('002', '1603002', '002', 6, '2019-08-05'),
('004', '1603002', '002', 7, '2019-08-07'),
('003', '1603002', '002', 8, '2019-08-06'),
('002', '1603004', '004', 8, '2019-08-08'),
('001', '1603004', '004', 7, '2019-08-10'),
('004', '1603004', '004', 5, '2019-08-13'),
('001', '1603007', '001', 8, '2019-08-06'),
('002', '1603007', '001', 5, '2019-08-08'),
('003', '1603007', '001', 6, '2019-08-09'),
('004', '1603008', '002', 7, '2019-08-08'),
('004', '1603008', '002', 7, '2019-08-01'),
('002', '1603008', '002', 5, '2019-08-02'),
('004', '1603011', '004', 4, '2019-08-01'),
('002', '1603011', '004', 8, '2019-08-03'),
('004', '1603011', '004', 7, '2019-08-04'),
('001', '1603013', '001', 8, '2019-08-01'),
('002', '1603013', '001', 8, '2019-08-02'),
('003', '1603013', '001', 8, '2019-08-03'),
('004', '1603015', '002', 7, '2019-08-05'),
('001', '1603015', '002', 8, '2019-08-06'),
('002', '1603015', '002', 7, '2019-08-07'),
('003', '1603016', '003', 8, '2019-08-09'),
('004', '1603016', '003', 7, '2019-08-10'),
('001', '1603016', '003', 7, '2019-08-11'),
('003', '1603017', '004', 7, '2019-08-12'),
('003', '1603017', '004', 7, '2019-08-02'),
('001', '1603018', '005', 6, '2019-08-01'),
('002', '1603018', '005', 7, '2019-08-02'),
('003', '1603018', '005', 5, '2019-08-03'),
('004', '1603019', '006', 3, '2019-08-13'),
('001', '1603019', '006', 4, '2019-08-03'),
('002', '1603019', '006', 5, '2019-08-23'),
('003', '1603020', '001', 5, '2019-08-01'),
('004', '1603020', '001', 7, '2019-08-11'),
('001', '1603020', '001', 6, '2019-08-21'),
('002', '1603021', '002', 8, '2019-08-02'),
('003', '1603021', '002', 8, '2019-08-12'),
('004', '1603021', '002', 8, '2019-08-22'),
('001', '1603022', '003', 5, '2019-08-03'),
('002', '1603022', '003', 6, '2019-08-13'),
('003', '1603022', '003', 7, '2019-08-23'),
('001', '1603023', '004', 4, '2019-08-01'),
('002', '1603023', '004', 3, '2019-08-11'),
('003', '1603023', '004', 7, '2019-08-21'),
('004', '1603024', '005', 8, '2019-08-02'),
('001', '1603024', '005', 8, '2019-08-22'),
('002', '1603024', '005', 8, '2019-08-12'),
('001', '1603003', '003', 8, '2019-08-01'),
('001', '1603003', '003', 8, '2019-08-02'),
('001', '1603003', '003', 7, '2019-08-05');

-- --------------------------------------------------------

--
-- Table structure for table `project`
--

CREATE TABLE `project` (
  `project_id` varchar(5) NOT NULL,
  `project_name` varchar(25) NOT NULL,
  `project_location` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `project`
--

INSERT INTO `project` (`project_id`, `project_name`, `project_location`) VALUES
('001', 'Googong Subdivision', 'Googong'),
('002', 'Googong Highway', 'Googong'),
('003', 'Burton Subdivision', 'Burton Canberra'),
('004', 'Burton Highway', 'Burton Canberra');

-- --------------------------------------------------------

--
-- Table structure for table `salary`
--

CREATE TABLE `salary` (
  `emp_id` varchar(10) NOT NULL,
  `basic` int(11) DEFAULT NULL,
  `net_salary` int(11) GENERATED ALWAYS AS (`basic` * 1.21) VIRTUAL,
  `salary_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `salary`
--

INSERT INTO `salary` (`emp_id`, `basic`, `salary_date`) VALUES
('1603001', 10000, '2019-09-01'),
('1603002', 8000, '2019-09-01'),
('1603004', 7500, '2019-09-02'),
('1603007', 6000, '2019-09-02'),
('1603008', 8000, '2019-09-01'),
('1603011', 7500, '2019-09-02'),
('1603013', 9000, '2019-09-01'),
('1603015', 6500, '2019-09-03'),
('1603016', 8500, '2019-09-02'),
('1603017', 10500, '2019-09-03'),
('1603018', 12000, '2019-09-01'),
('1603019', 540, '2019-09-05'),
('1603020', 720, '2019-09-08'),
('1603021', 10000, '2019-09-03'),
('1603022', 7500, '2019-09-04'),
('1603023', 6000, '2019-09-02'),
('1603024', 8000, '2019-09-03'),
('1603025', 6500, '2019-09-03'),
('1603003', 1035, '2019-09-03');

--
-- Triggers `salary`
--
DELIMITER $$
CREATE TRIGGER `before_salary_insert` BEFORE INSERT ON `salary` FOR EACH ROW BEGIN
    	IF((SELECT employee.type_of_work FROM employee WHERE employee.emp_id = NEW.emp_id) = 'P')
        	THEN
            	SET NEW.basic = (SELECT employee.hourly_rate FROM employee WHERE employee.emp_id = NEW.emp_id) * (SELECT SUM(ft_pt_work.num_of_hours) FROM ft_pt_work WHERE ft_pt_work.emp_id = NEW.emp_id);
        END IF;
        IF(((SELECT employee.type_of_work FROM employee WHERE employee.emp_id = NEW.emp_id) = 'F') AND NEW.basic < 5000)
        	THEN
            	SIGNAL SQLSTATE '46001'
                SET MESSAGE_TEXT = 'Basic for full-time worker cannot be less than $5000.';
        END IF;
    END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Structure for view `employee_info`
--
DROP TABLE IF EXISTS `employee_info`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `employee_info`  AS  select `employee`.`emp_name` AS `Name`,`dept`.`dept_name` AS `Department`,`employee`.`type_of_work` AS `type_of_work`,`salary`.`basic` AS `Basic`,`salary`.`basic` * 0.45 AS `allowance`,`salary`.`basic` * 0.24 AS `deduction`,`salary`.`net_salary` AS `Salary` from ((`employee` join `dept`) join `salary`) where `dept`.`dept_id` = `employee`.`dept_id` and `salary`.`emp_id` = `employee`.`emp_id` ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `address`
--
ALTER TABLE `address`
  ADD KEY `emp_id` (`emp_id`);

--
-- Indexes for table `dept`
--
ALTER TABLE `dept`
  ADD PRIMARY KEY (`dept_id`);

--
-- Indexes for table `employee`
--
ALTER TABLE `employee`
  ADD PRIMARY KEY (`emp_id`),
  ADD KEY `dept_id` (`dept_id`);

--
-- Indexes for table `ft_pt_work`
--
ALTER TABLE `ft_pt_work`
  ADD KEY `project_id` (`project_id`),
  ADD KEY `emp_id` (`emp_id`),
  ADD KEY `dept_id` (`dept_id`);

--
-- Indexes for table `project`
--
ALTER TABLE `project`
  ADD PRIMARY KEY (`project_id`);

--
-- Indexes for table `salary`
--
ALTER TABLE `salary`
  ADD KEY `emp_id` (`emp_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `address`
--
ALTER TABLE `address`
  ADD CONSTRAINT `address_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`);

--
-- Constraints for table `employee`
--
ALTER TABLE `employee`
  ADD CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`dept_id`) REFERENCES `dept` (`dept_id`);

--
-- Constraints for table `ft_pt_work`
--
ALTER TABLE `ft_pt_work`
  ADD CONSTRAINT `ft_pt_work_ibfk_1` FOREIGN KEY (`project_id`) REFERENCES `project` (`project_id`),
  ADD CONSTRAINT `ft_pt_work_ibfk_2` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`),
  ADD CONSTRAINT `ft_pt_work_ibfk_3` FOREIGN KEY (`dept_id`) REFERENCES `dept` (`dept_id`);

--
-- Constraints for table `salary`
--
ALTER TABLE `salary`
  ADD CONSTRAINT `salary_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
