import { Book } from "./book";
import { ImagedLink } from "./imaged-link";

export interface Course {
    courseId: string,
    courseTitle: string,
    resources?: ImagedLink[],
    books?: Book[]
}
