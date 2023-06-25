import { NgModule } from '@angular/core';
import { RouterModule, Routes, UrlSegment } from '@angular/router';
import { ResourcesComponent } from './components/resources/resources.component';
import { AcademicComponent } from './components/academic/academic.component';

const routes: Routes = [
    {
        path: 'resources',
        component: ResourcesComponent
    },
    {
        path: '',
        redirectTo: '/resources',
        pathMatch: 'full'
    },
    {
        matcher: (url) => {
            if (url[0].path.includes("year")) {
                return {
                    consumed: url,
                    posParams: {
                        path: new UrlSegment(url[0].path, {})
                    }
                };
            }
            return null;
        },
        component: AcademicComponent
    },
];

@NgModule({
    imports: [RouterModule.forRoot(routes)],
    exports: [RouterModule]
})
export class AppRoutingModule { }
