import { NgModule } from '@angular/core';
import { RouterModule, Routes, UrlSegment } from '@angular/router';
import { ResourcesComponent } from './components/resources/resources.component';
import { AcademicComponent } from './components/academic/academic.component';
import { PathNotFoundComponent } from './components/path-not-found/path-not-found.component';

const routes: Routes = [
    {
        path: '',
        redirectTo: '/resources',
        pathMatch: 'full'
    },
    {
        path: 'resources',
        component: ResourcesComponent
    },
    {
        path: '404',
        component: PathNotFoundComponent
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
    {
        path: '**',
        redirectTo: '/404'
    },
];

@NgModule({
    imports: [RouterModule.forRoot(routes)],
    exports: [RouterModule]
})
export class AppRoutingModule { }
