import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ResourcesComponent } from './components/resources/resources.component';
import { AcademicComponent } from './components/academic/academic.component';

@NgModule({
    declarations: [
        AppComponent,
        ResourcesComponent,
        AcademicComponent
    ],
    imports: [
        BrowserModule,
        AppRoutingModule
    ],
    providers: [],
    bootstrap: [AppComponent]
})
export class AppModule { }
