import { Component } from '@angular/core';
import { ImagedLink } from 'src/app/models/imaged-link';

@Component({
    selector: 'app-resources',
    templateUrl: './resources.html',
    styleUrls: ['./resources.css']
})
export class ResourcesComponent {
    resources: ImagedLink[] = [
        {
            link: 'https://www.overleaf.com/read/kbjnwsnsgtyv',
            image: 'https://img.shields.io/badge/Overleaf-Front Cover Template-blueberry?style=for-the-badge&logo=overleaf'
        },
        {
            link: 'https://t.me/joinchat/V-3m4AQ42mFusDJz',
            image: 'https://img.shields.io/badge/Telegram-PDF Collection-blue?style=for-the-badge&logo=telegram'
        },
        {
            link: 'https://drive.google.com/drive/u/0/folders/1S5eJwi61FutDBnhYGml0QVF5KA49RnEJ',
            image: 'https://img.shields.io/badge/Drive-Question Solve-green?style=for-the-badge&logo=googledrive'
        },
        {
            link: "https://drive.google.com/drive/u/0/folders/1AUcg28IPtpAiYlQ4PX8SPld7lo1FOk9v",
            image: "https://img.shields.io/badge/drive-Thesis Books-green?logo=googledrive"
        },
        {
            link: "https://drive.google.com/drive/u/0/folders/1cLoL9d6EYDt9CifC4Q-5ZeXWVfh0KFZh",
            image: "https://img.shields.io/badge/drive-Research-green?logo=googledrive"
        },
        {
            link: "https://drive.google.com/drive/u/0/folders/1x7B7MHwj8frwVeeIalfQUmECB8yV-r52",
            image: "https://img.shields.io/badge/drive-Machine Learning-green?logo=googledrive"
        },
        {
            link: "https://t.me/c/1475208928/2282",
            image: "https://img.shields.io/badge/Ragib Hasan-গবেষণায় হাতেখড়ি-blue?logo=telegram"
        },
        {
            link: "https://www.overleaf.com/read/fwzgfjndfhsc",
            image: "https://img.shields.io/badge/Overleaf-Thesis book template-blueberry?logo=overleaf"
        },
    ];
}
