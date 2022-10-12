import { BrowserRouter, Routes, Route } from "react-router-dom";
import GraphVitAcc from './GraphVitAcc';
import Nav from './Nav';

function Router() {
  return (
    <div className="App">
        <BrowserRouter>
            <Routes>
                <Route path="/" element={
                    <Nav>
                        <GraphVitAcc />
                    </Nav>
                }/>
            </Routes>
        </BrowserRouter>
    </div>
  );
}

export default Router;
