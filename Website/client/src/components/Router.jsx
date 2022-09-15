import { BrowserRouter, Routes, Route } from "react-router-dom";
import GraphVitAcc from './GraphVitAcc';
import GraphAlPreTem from './GraphAlPreTem';
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
                <Route path="alPreTem" element={
                    <Nav>
                        <GraphAlPreTem />
                    </Nav>
                } />
            </Routes>
        </BrowserRouter>
    </div>
  );
}

export default Router;
