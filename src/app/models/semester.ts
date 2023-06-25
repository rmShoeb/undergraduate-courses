import { Course } from "./course";
import { ImagedLink } from "./imaged-link";

export interface Semester {
    courses: Course[],
    resources?: ImagedLink[],
}
