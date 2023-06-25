import { Injectable } from "@angular/core";
import { AcademicYear } from "src/app/models/academic-year";

@Injectable({
    providedIn: 'root',
})
export class Records {
    firstYear: AcademicYear = {
        oddSemester: {
            courses: [
                {
                    courseId: 'CSE 1100',
                    courseTitle: 'Computer Fundamentals and Ethics'
                },
                {
                    courseId: 'CSE 1101',
                    courseTitle: 'Computer Programming',
                    books: [
                        {
                            title: 'C++: The Complete Reference',
                            author: 'Herbert Schildt',
                            link: 'https://www.pdfdrive.com/the-art-of-c-by-herbert-schildt-e33457826.html'
                        },
                        {
                            title: 'Programming in ANSI C',
                            author: 'Balagurusamy',
                            link: 'https://t.me/c/1475208928/1318'
                        },
                        {
                            title: 'Solutions to Programming in ANSI C',
                            author: 'Balagurusamy',
                            link: 'https://t.me/c/1475208928/1319'
                        },
                        {
                            title: 'Computer programming',
                            author: 'Tamim Shariar Subeen',
                            link: 'https://t.me/c/1475208928/1323'
                        }
                    ]
                },
                {
                    courseId: 'EEE 1151',
                    courseTitle: 'Basic Electrical Engineering',
                    books: [
                        {
                            title: 'Fundamentals of Electric Circuits',
                            author: 'Charles K. Alexander and Mathew N.O. Sadiku',
                            link: 'https://www.pdfdrive.com/fundamentals-of-electric-circuits-alexander-and-sadiku-5th-ed-e201213118.html'
                        },
                        {
                            title: 'Solution to Fundamentals of Electric Circuits',
                            author: 'Charles K. Alexander and Mathew N.O. Sadiku',
                            link: 'https://www.pdfdrive.com/solution-fundamentals-alexander-matthew-sadiku-3rd-ed-e201213125.html'
                        },
                        {
                            title: 'Introductory Circuit Analysis',
                            author: 'Robert L. Boylestad',
                            link: 'https://t.me/c/1475208928/680'
                        },
                        {
                            title: 'Solution to Introductory Circuit Analysis',
                            author: 'Robert L. Boylestad',
                            link: 'https://t.me/c/1475208928/679'
                        }
                    ]
                },
                {
                    courseId: 'Math 1113',
                    courseTitle: 'Differential and Integral Calculus',
                    books: [
                        {
                            title: 'Integral Calculus and Differential Calcus',
                            author: 'B.C Das and Mukherjee',
                            link: 'https://t.me/c/1475208928/753'
                        }
                    ]
                },
                {
                    courseId: 'Hum 1113',
                    courseTitle: 'Functional English'
                },
                {
                    courseId: 'Hum 1114',
                    courseTitle: 'English Language Lab',
                    books: [
                        {
                            title: 'IELTS Academic 17: With Answers',
                            link: 'https://t.me/c/1475208928/3535'
                        }
                    ]
                },
                {
                    courseId: 'Chem 1113',
                    courseTitle: 'Inorganic and Physical Chemistry',
                    books: [
                        {
                            title: 'Modern Inorganic Chemistry',
                            author: 'Butterworth & Co',
                            link: 'https://t.me/c/1475208928/2600'
                        }
                    ]
                },
            ]
        },
        evenSemester: {
            courses: [
                {
                    courseId: 'CSE 1200',
                    courseTitle: 'Analytical Programming',
                },
                {
                    courseId: 'CSE 1201',
                    courseTitle: 'Data Structures',
                    books: [
                        { title: 'Data Structures with C', author: 'Seymour Lipschutz', link: 'https://t.me/c/1475208928/1492' },
                        { title: 'Computer Programming Data Structure', author: 'Tamim Sahriar Subin', link: 'https://t.me/c/1475208928/2447' }
                    ]
                },
                {
                    courseId: 'CSE 1203',
                    courseTitle: 'Object Oriented Programming',
                    books: [
                        { title: 'C++: The Complete Reference', author: 'Herbert Schildt', link: 'https://www.pdfdrive.com/the-art-of-c-by-herbert-schildt-e33457826.html' },
                        { title: "Java: A Beginner's Guide", author: 'Herbert Schildt', link: 'https://www.pdfdrive.com/java-a-beginners-guide-eighth-edition-e185753177.html' }
                    ]
                },
                { courseId: 'Hum 1213', courseTitle: 'Ecnomics, Government and Sociology' },
                {
                    courseId: 'Math 1213',
                    courseTitle: 'Co-ordinate Geometry and Ordinary Differential Function',
                    books: [
                        { title: 'Differential Equations', author: 'S.L. Ross', link: 'https://www.pdfdrive.com/differential-equation-sl-ross-e201213132.html' },
                        { title: 'A Text Book On Of Co Ordinate Geometry With Vector Analysis', author: 'Abdur Rahman', link: 'https://t.me/c/1475208928/3394' }
                    ]
                },
                {
                    courseId: 'Phy 1213',
                    courseTitle: 'Physics',
                    books: [
                        { title: 'Physics', link: 'https://t.me/c/1475208928/101' }
                    ]
                },
                {
                    courseId: 'Phy 1214',
                    courseTitle: 'Sesional based on Phy 1214',
                    books: [
                        {
                            title: 'Practical Physics',
                            author: 'Dr Giasuddin Ahmad and Md Shahabudin',
                            link: 'https://www.academia.edu/26609739/Practical_physics_by_dr_giasuddin_ahmad_and_md_shahabudin'
                        }
                    ]
                }
            ]
        }
    };
    secondYear: AcademicYear = {
        oddSemester: {
            courses: [
                {
                    courseId: 'CSE 2101',
                    courseTitle: 'Discrete Mathematics',
                    books: [
                        {
                            title: 'Discrete Mathematics and Its Applications',
                            author: 'Keneth H. Rosen',
                            link: 'https://www.pdfdrive.com/discrete-mathematics-applications-e86266202.html'
                        },
                        {
                            title: 'Solution to Discrete Mathematics and Its Applications',
                            link: 'https://www.pdfdrive.com/solution-to-discrete-mathematics-and-its-applications-e201231052.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 2103',
                    courseTitle: 'Numerical Methods',
                    books: [
                        { title: 'Numerical Methods in Engineering and Science', author: 'B. S. Grewal', link: 'https://t.me/c/1475208928/309' },
                        { title: 'Solution Manual For Numerical Methods For Engineers', author: 'Chapra', link: 'https://t.me/c/1475208928/2152' }
                    ]
                },
                {
                    courseId: 'EEE 2151',
                    courseTitle: 'Analog Electronics',
                    books: [
                        {
                            title: 'Electronic Devices and Circuit Theory',
                            author: 'Robert L. Boylestad, Louis Nashelsky',
                            link: 'https://www.pdfdrive.com/electronic-devices-and-circuit-theory-by-robert-l-boylestad-louis-nashelsky-pearson-11th-edition-e200834110.html'
                        },
                        {
                            title: 'Solution to Electronic Devices and Circuit Theory',
                            link: 'https://www.pdfdrive.com/solution-introductory-circuit-analysis-boylestad-11th-ed-e201231059.html'
                        },
                        {
                            title: 'Principles of Electronics',
                            author: 'V.K. Mehta and Rohit Mehta',
                            link: 'https://www.pdfdrive.com/principle-of-electronics-vk-mehta-e201213139.html'
                        },
                        {
                            title: 'Op',
                            link: 'https://www.pdfdrive.com/op-amps-and-linear-integrated-circuits-4th-edition-e187947439.html'
                        },
                        {
                            title: 'Analog Electronics with LabVIEW',
                            author: 'Kenneth L. Ashley',
                            link: 'https://www.pdfdrive.com/analog-electronics-with-labview-e18770419.html'
                        }
                    ]
                },
                {
                    courseId: 'HUM 2113',
                    courseTitle: 'Industrial Management and Accountancy',
                    books: [
                        {
                            title: 'Accounting Principles',
                            author: 'Jerry Weygandt',
                            link: 'https://www.pdfdrive.com/accounting-principles-12th-edition-by-jerry-weygandt-drsoc-e28734318.html'
                        },
                        {
                            title: 'Financial Accounting',
                            link: 'https://www.pdfdrive.com/financial-accounting-11th-global-edgnv64-e201205957.html'
                        },
                        {
                            title: 'Managerial Accounting',
                            author: 'Garrison, 14th edition',
                            link: 'https://www.pdfdrive.com/managerial-accounting-garrison-14th-edition-e201231073.html'
                        },
                        {
                            title: 'Solution to Manegerial Accounting',
                            author: 'Garrison',
                            link: 'https://www.pdfdrive.com/solution-to-mangerial-accounting-garrison-e201213146.html'
                        },
                        {
                            title: 'Management',
                            author: 'Richard L. Daft',
                            link: 'https://www.pdfdrive.com/management-e192943206.html'
                        },
                        {
                            title: 'Management',
                            author: 'Ricky W. Griffin',
                            link: 'https://www.pdfdrive.com/management-e188227432.html'
                        },
                        {
                            title: 'Fundamentals of Management',
                            author: 'Ricky W. Griffin',
                            link: 'https://www.pdfdrive.com/fundamentals-of-management-ricky-w-griffin-e201213153.html'
                        },
                        {
                            title: 'Management and Cost Accounting, tenth edition',
                            link: 'https://www.pdfdrive.com/management-and-cost-accounting-tenth-edition-e201231066.html'
                        }
                    ]
                },
                {
                    courseId: 'Math 2113',
                    courseTitle: 'Vector Analysis and Linear Algebra',
                    books: [
                        {
                            title: "Schaum's outlines: Linear algebra",
                            author: 'Seymour Lipschutz, Marc Lars Lipson, sixth edition',
                            link: 'https://www.pdfdrive.com/schaums-outlines-linear-algebra-e158392473.html'
                        },
                        {
                            title: "Schaum's outline: Theory and Problems of Linear Algebra",
                            author: 'Lipschutz S. and Lipson M., third edition',
                            link: 'https://www.pdfdrive.com/schaums-outline-of-theory-and-problems-of-linear-algebra-e164843239.html'
                        },
                        {
                            title: "Schaum's outline: Vector Analysis and an Introduction to Tensor Analysis",
                            author: 'Murray R. Spiegel',
                            link: 'https://www.pdfdrive.com/vector-analysis-e38220594.html'
                        },
                        {
                            title: 'Matrices',
                            author: 'PN Chatterjee',
                            link: 'https://www.scribd.com/document/433667289/Matrices-by-PN-Chatterjee'
                        }
                    ]
                }
            ]
        },
        evenSemester: {
            courses: [
                {
                    courseId: 'CSE 2201',
                    courseTitle: 'Computer Algorithms',
                    books: [
                        {
                            title: 'Introduction to Algorithms',
                            author: 'Thomas H. Cormen',
                            link: 'https://www.pdfdrive.com/introduction-to-algorithms-third-edition-e42987274.html'
                        },
                        {
                            title: 'The Spirit of Computing',
                            author: 'David Harel, third edition',
                            link: 'https://t.me/c/1475208928/189'
                        }
                    ]
                },
                {
                    courseId: 'CSE 2203',
                    courseTitle: 'Digital Techniques',
                    books: [
                        {
                            title: 'Digital Systems: Principles and Applications',
                            author: 'Tocci, Widmer, and Moss, tenth edition',
                            link: 'https://www.pdfdrive.com/digital-systems-principles-and-applications-e33416544.html'
                        },
                        {
                            title: 'Digital Logic and Computer Design',
                            author: 'M. Morris Mano, fifth edition',
                            link: 'https://www.pdfdrive.com/digital-design-morris-mano-fifth-edition-e201253837.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 2205',
                    courseTitle: 'Finite Automata Theory',
                    books: [
                        {
                            title: 'Introduction to Automata Theory: Languages, and Computation',
                            author: 'Hopcroft, third edition',
                            link: 'https://www.pdfdrive.com/introduction-to-automata-theory-languages-and-computations-e184570093.html'
                        }
                    ]
                },
                {
                    courseId: 'EEE 2251',
                    courseTitle: 'Electrical Machines and Instrumentations',
                    books: [
                        {
                            title: 'Electrical Machines',
                            author: 'B.L. Theraja',
                            link: 'https://www.pdfdrive.com/electrical-machines-bl-theraja-e201213160.html'
                        }
                    ],
                    resources: [
                        {
                            link: "https://docs.google.com/document/d/1v-8Ua5QHKns8lNNpw7yhNLZmj6ZaLqrpyeKiR8ftZjw/edit",
                            image: "https://img.shields.io/badge/docs-Shegufa CSE 16-blue?logo=googledocs"
                        }
                    ]
                },
                {
                    courseId: 'Math 2213',
                    courseTitle: 'Complex Variable, Differential Equations and Harmonic Analysis',
                    books: [
                        {
                            title: "Schaum's Complex Variables",
                            link: 'https://www.pdfdrive.com/schaums-complex-variables-e18720112.html'
                        }
                    ]
                },
            ]
        }
    };
    thirdYear: AcademicYear = {
        oddSemester: {
            courses: [
                {
                    courseId: 'CSE 3101',
                    courseTitle: 'Database Systems',
                    books: [
                        {
                            title: 'Database System Concepts',
                            author: 'Silvershatz, sixth edition',
                            link: 'https://www.pdfdrive.com/database-system-concepts-silvershatz-6e-e201253886.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 3103',
                    courseTitle: 'Data Communication',
                    books: [
                        {
                            title: 'Data Communications and Networking',
                            author: 'Forouzan, fifth edition',
                            link: 'https://www.pdfdrive.com/data-communications-and-networking-forouzan-5th-ed-e201253900.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 3105',
                    courseTitle: 'Software Engineering',
                    books: [
                        { title: 'Software Engineering', author: 'Roger S. Pressman', link: 'https://t.me/c/1475208928/233' }
                    ]
                },
                {
                    courseId: 'CSE 3107',
                    courseTitle: 'Applied Statistics and Queuing Theory',
                    books: [
                        {
                            title: 'Probability and Statistical Inference',
                            author: 'Hogg and Tanis, ninth Edition',
                            link: 'https://www.pdfdrive.com/probability-and-statistical-inference-9th-edition-e181725699.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 3109',
                    courseTitle: 'Microprocessors and Assembly Language',
                    books: [
                        {
                            title: 'Assembly Language Programming Organization of the IBM PC',
                            author: 'Yu and Marut',
                            link: 'https://www.pdfdrive.com/assembly-language-programming-organization-of-the-ibm-pc-e165856727.html'
                        },
                        {
                            title: 'The Intel microprocessors (8086/8088,...): Architecture, Programming, and Interfacing',
                            author: 'Barry B. Brey, eighth edition',
                            link: 'pdfdrive.com/the-intel-microprocessors-80868088-8018680188-80286-80386-80486-the-architecture-programming-and-interfacing-8th-edition-e158290350.html'
                        }
                    ]
                },
            ]
        },
        evenSemester: {
            resources: [
                {
                    link: "https://drive.google.com/drive/folders/1satJnd_RbM638foWdIZC0mbIc2BSv-Ji",
                    image: "https://img.shields.io/badge/drive-Akash CSE 16-green?logo=googledrive"
                },
                {
                    link: "https://drive.google.com/drive/folders/1yix9nxDOlfnKJo7GMYGQjBw1NXrkLRV8",
                    image: "https://img.shields.io/badge/drive-Shuvra CSE 16-green?logo=googledrive"
                },
                {
                    link: "https://drive.google.com/drive/u/0/folders/1mtradzQh6GNNmQH03SZFx4FEzZav8NQ8",
                    image: "https://img.shields.io/badge/drive-Sadat CSE 16-green?logo=googledrive"
                },
                {
                    link: "https://drive.google.com/drive/folders/1qFRzy1TWGPT843ZKKcHZYHV5dEL1Q4l1",
                    image: "https://img.shields.io/badge/drive-Durlov CSE 16-green?logo=googledrive"
                }
            ],
            courses: [
                {
                    courseId: 'CSE 3201',
                    courseTitle: 'Operating Systems',
                    books: [
                        {
                            title: 'Modern Operating Systems',
                            author: 'Andrew S. Tanenbaum, fourth edition',
                            link: 'https://www.pdfdrive.com/modern-operating-systems-4th-edition-e175928348.html'
                        },
                        {
                            title: 'Operating System Concepts',
                            author: 'Abraham SilverShatz, tenth edition',
                            link: 'https://www.pdfdrive.com/operating-system-concepts-silvershatz-10th-edition-e201252542.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 3203',
                    courseTitle: 'Computer Architecture and Design',
                    books: [
                        {
                            title: 'Computation Structures',
                            link: 'https://computationstructures.org/lectures/info/info.html'
                        },
                        {
                            title: 'Computer Organization and Architecture Designing for Performance',
                            author: 'William Stallings, tenth edition',
                            link: 'https://www.pdfdrive.com/computer-organization-and-architecture-designing-for-performance-william-stallings-10e-e201252549.html'
                        },
                        {
                            title: 'The Essentials of Computer Organization and Architecture',
                            author: 'Linda Null and Julia Lobur',
                            link: 'https://www.pdfdrive.com/essentials-of-computer-organization-and-architecture-e195270552.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 3205',
                    courseTitle: 'Computer Networks',
                    books: [
                        {
                            title: 'Computer networks',
                            author: 'Tanenbaum and Wetherall',
                            link: 'https://www.pdfdrive.com/computer-networks-e175307056.html'
                        },
                        {
                            title: 'Data Communications and Networking',
                            author: 'Behrouz A. Forouzan',
                            link: 'https://www.pdfdrive.com/data-communications-and-networking-by-behrouz-a-e201252556.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 3207',
                    courseTitle: 'Peripherals and Interfacings',
                    books: [
                        {
                            title: 'Digital Systems: Principles and Applications',
                            author: 'Tocci, Widmer, and Moss, tenth edition',
                            link: 'https://www.pdfdrive.com/digital-systems-principles-and-applications-e33416544.html'
                        },
                        {
                            title: 'The Intel microprocessors (8086/8088,...): Architecture, Programming, and Interfacing',
                            author: 'Barry B. Brey',
                            link: 'pdfdrive.com/the-intel-microprocessors-80868088-8018680188-80286-80386-80486-the-architecture-programming-and-interfacing-8th-edition-e158290350.html'
                        },
                        {
                            title: 'Microprocessors and Interfacing',
                            author: 'Douglas V Hall',
                            link: '#'
                        }
                    ]
                },
                {
                    courseId: 'CSE 3209',
                    courseTitle: 'Artificial Intelligence',
                    books: [
                        {
                            title: 'Artificial Intelligence: A Modern Approach',
                            author: 'Stuart Russel and Peter Norvig',
                            link: 'https://www.pdfdrive.com/artificial-intelligence-a-modern-approach-3rd-editionpdf-e34335863.html'
                        }
                    ]
                },
            ]
        }
    };
    fourthYear: AcademicYear = {
        oddSemester: {
            resources: [
                {
                    link: "https://drive.google.com/drive/folders/1j2dUjrM1h-tbbZCoRa4ZSY1yGDCTeebU",
                    image: "https://img.shields.io/badge/drive-Ismail CSE 15-green?logo=googledrive"
                },
                {
                    link: "https://drive.google.com/drive/folders/17p1S6gHp5M1_yL-3BihQZcsd-W2Amhvo",
                    image: "https://img.shields.io/badge/drive-Durlov CSE 16-green?logo=googledrive"
                },
                {
                    link: "https://drive.google.com/drive/u/0/folders/1E3RhgyEXHzdOg2JJeJKQk24gYLY_Nhfo",
                    image: "https://img.shields.io/badge/drive-Akash CSE 16-green?logo=googledrive"
                },
                {
                    link: "https://drive.google.com/drive/folders/1cXI2GNA5VNTayX9DXzwKe6SMZE44DAqe",
                    image: "https://img.shields.io/badge/drive-Akash CSE 16-green?logo=googledrive"
                },
                {
                    link: "https://drive.google.com/drive/u/0/folders/1iJXOOQphVo-AB_pC6vzuof87QeXpl1UH",
                    image: "https://img.shields.io/badge/drive-Questions collection-green?logo=googledrive"
                },
            ],
            courses: [
                {
                    courseId: 'CSE 4101',
                    courseTitle: 'Compiler Design',
                    books: [
                        {
                            title: 'Compilers: Principles, Techniques & Tools',
                            author: 'Alfred V. Aho, Monica S. Lam, Ravi Sethi and Jeffrey D. Ullman',
                            link: 'https://www.pdfdrive.com/compilers-principles-techniques-and-tools-e178430400.html'
                        },
                        {
                            title: 'Engineering a Compiler',
                            author: 'Keith D. Cooper and Linda Torczon',
                            link: 'https://www.pdfdrive.com/engineering-a-compiler-2nd-edition-by-cooper-and-torczon-e33452800.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4102',
                    courseTitle: 'Sessional Based on CSE 4101',
                    books: [
                        {
                            title: 'Lex & Yacc',
                            author: 'John R. Levine, Tony Mason and Doug Brown',
                            link: 'https://www.pdfdrive.com/lex-yacc-2nd-edition-e48298367.html'
                        },
                        {
                            title: 'Flex & Bison',
                            author: 'John Levine',
                            link: 'https://www.pdfdrive.com/flex-bison-text-processing-tools-e164705178.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4103',
                    courseTitle: 'Digital Signal Processing',
                    books: [
                        {
                            title: 'Digital Signal Processing: Principles, Algorithms & Applications',
                            author: 'John G. Proakis and Dimitris G. Manolakis',
                            link: 'https://www.pdfdrive.com/digital-signal-processing-4th-ed-ocr-e166956847.html'
                        },
                        {
                            title: 'Digital Signal Processing (4th Edition by Proakis and Manolakis) Solution',
                            link: 'https://www.pdfdrive.com/digital-signal-processing-4th-edition-by-proakis-manolakis-solution-e39913431.html'
                        }
                    ],
                    resources: [
                        {
                            link: "https://drive.google.com/drive/folders/13KCV0nObxuCpXRPpFSWqjLM_CDBPjOtJ",
                            image: "https://img.shields.io/badge/drive-Farhan CSE 16-green?logo=googledrive"
                        }
                    ]
                },
                {
                    courseId: 'CSE 4104',
                    courseTitle: 'Sessional based on CSE 4103',
                    books: [
                        {
                            title: 'Digital Signal Processing Using MATLAB',
                            link: 'https://www.pdfdrive.com/3digital-signal-processing-using-matlab-3rd-edition-slicer-e37316683.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4105',
                    courseTitle: 'Digital Image Processing',
                    books: [
                        {
                            title: 'Digital Image Processing',
                            author: 'Gonzalez',
                            link: 'https://www.pdfdrive.com/digital-image-processing-gonzalez-4th-edition-e201239851.html'
                        },
                        {
                            title: 'Digital Image Processing',
                            author: 'Pratt',
                            link: 'https://www.pdfdrive.com/digital-image-processing-pratt-4th-edition-e201245199.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4106',
                    courseTitle: 'Sessional Based on CSE 4105',
                    books: [
                        {
                            title: 'Digital Image Processing Using MATLAB',
                            link: 'https://www.pdfdrive.com/digital-image-processing-using-matlab-e157365083.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4107',
                    courseTitle: 'System Analysis and Design',
                    books: [
                        {
                            title: 'Systems Analysis and Design',
                            author: 'Elias M. Awad',
                            link: 'https://www.pdfdrive.com/systems-analysis-and-design-elias-m-e201235798.html'
                        },
                        {
                            title: 'System Analysis and Design',
                            author: 'Tutorialspoint',
                            link: 'https://www.pdfdrive.com/system-analysis-and-design-tutorialspoint-e201235805.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4117',
                    courseTitle: 'Parallel and Distributed Processing',
                    books: [
                        {
                            title: 'Distributed Systems',
                            author: 'Maarten van Steen and Andrew S. Tanenbaum',
                            link: 'https://www.pdfdrive.com/lex-yacc-2nd-edition-e48298367.html'
                        },
                        {
                            title: 'Distributed Operating System',
                            author: 'Andrew S. Tanenbaum',
                            link: 'https://www.pdfdrive.com/distributed-operating-system-tanenbaum-e201211585.html'
                        },
                        {
                            title: 'Computer Organization and Architecture: Designing for Performance',
                            author: 'William Stallings',
                            link: 'https://www.pdfdrive.com/computer-organization-and-architecture-designing-for-performance-william-stallings-10e-e201231031.html'
                        },
                        {
                            title: 'Computer Architecture and Parallel Processing',
                            author: 'Kai Hwang and Faye A. Briggs',
                            link: 'https://www.pdfdrive.com/computer-architecture-and-parallel-processing-hwang-brigg-e201230541.html'
                        }
                    ],
                    resources: [
                        {
                            link: "https://drive.google.com/drive/folders/1icT-CGV7Aa1oH5z1SyZjpZso4APyuYKC",
                            image: "https://img.shields.io/badge/drive-Assignment-green?logo=googledrive"
                        }
                    ]
                },
            ]
        },
        evenSemester: {
            resources: [
                {
                    link: "https://drive.google.com/drive/u/0/folders/1QHf6DYxs8298cfpBlxxGudlRYuSX-5sA",
                    image: "https://img.shields.io/badge/drive-Muntashir CSE 16-green?logo=googledrive"
                }
            ],
            courses: [
                {
                    courseId: 'CSE 4201',
                    courseTitle: 'Computer Graphics and Animations',
                    books: [
                        {
                            title: "Schaum's Outline of Theory and Problems of Computer Graphics",
                            author: 'Zhigang Xiang and Roy A. Plastock',
                            link: 'https://www.pdfdrive.com/schaums-outline-of-theory-and-problems-of-computer-graphics-zhigang-xiang-and-roy-a-plastock-e201351137.html'
                        },
                        {
                            title: 'Computer Graphics: Principles and Practice',
                            author: 'John F. Hughes, David F. Sklar, James D. Foley, Steven K. Feiner and Kurt Akeley',
                            link: 'https://www.pdfdrive.com/computer-graphics-principles-and-practice-e175830467.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4203',
                    courseTitle: 'Neural Networks and Fuzzy Systems',
                    books: [
                        {
                            title: 'Neural Computing: An Introduction',
                            author: 'R Beale and T Jackson',
                            link: 'https://doost.profile.semnan.ac.ir/downloads/file/7491'
                        },
                        {
                            title: 'An Introduction to Support Vector Machines and Other Kernel based Learning Methods',
                            link: 'https://www.pdfdrive.com/an-introduction-to-support-vector-machines-and-other-kernel-based-learning-methods-e183554841.html'
                        },
                        {
                            title: 'Neural Networks, Fuzzy Logic and Genetic Algorithms: Synthesis and Applications',
                            author: 'S. Rajasekaran and G.A. Vijayalakshmi Pai',
                            link: '#'
                        }
                    ],
                    resources: [
                        {
                            link: "https://www.youtube.com/playlist?list=PLYwpaL_SFmcDHUTN26NXKfjg6wFJKDO9R",
                            image: "https://img.shields.io/badge/youtube-Genetic Algorithm-red?logo=youtube"
                        }
                    ]
                },
                {
                    courseId: 'CSE 4207',
                    courseTitle: 'VLSI Design',
                    books: [
                        {
                            title: 'Design of VLSI Systems: A Practical Introduction',
                            author: 'Linda E.M. Brackendury',
                            link: 'https://www.pdfdrive.com/design-of-vlsi-systems-a-practical-introduction-linda-e-e201257617.html'
                        },
                        {
                            title: 'Basic VLSI Design',
                            author: 'Douglas A. Pucknell and Kamran Eshraghian',
                            link: 'https://www.pdfdrive.com/basic-vlsi-design-pucknell-3rd-edition-e201367237.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4215',
                    courseTitle: 'Network Security',
                    books: [
                        {
                            title: 'Cryptography and Network Security: Principles and Practice',
                            author: 'William Stallings',
                            link: 'https://www.pdfdrive.com/cryptography-and-network-security-principles-and-practice-e201362316.html'
                        }
                    ]
                },
                {
                    courseId: 'CSE 4221',
                    courseTitle: 'Data Mining',
                    books: [
                        {
                            title: 'Data Mining: Concepts and Techniques',
                            author: 'Han, Kamber and Pei',
                            link: 'https://www.pdfdrive.com/data-mining-concepts-and-techniques-3rd-edition-han-and-kamber-e201358767.html'
                        }
                    ]
                },
            ]
        }
    };
}
