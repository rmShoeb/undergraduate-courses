import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, ParamMap, Router } from '@angular/router';
import { map } from 'rxjs/operators';
import { AcademicYear } from 'src/app/models/academic-year';
import { Records } from './records';

@Component({
    selector: 'app-academic',
    templateUrl: './academic.html',
    styleUrls: ['./academic.css']
})
export class AcademicComponent implements OnInit {
    resourceToShow: AcademicYear = {oddSemester: {courses: []}, evenSemester: {courses: []}};

    constructor(
        private activatedRoute: ActivatedRoute,
        private router: Router,
        private records: Records
    ) { }

    ngOnInit(): void {
        this.activatedRoute.paramMap.pipe(map((params: ParamMap)=>{
            return params.get("path");
        })).subscribe(path => {
            if(path=='first-year'){
                this.resourceToShow = this.records.firstYear;
            } else if(path=='second-year'){
                this.resourceToShow = this.records.secondYear;
            } else if(path=='third-year'){
                this.resourceToShow = this.records.thirdYear;
            } else if(path=='fourth-year'){
                this.resourceToShow = this.records.fourthYear;
            } else {
                this.router.navigateByUrl("page-not-found");
            }
        });
    }
}
